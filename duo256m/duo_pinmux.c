#include "devmem.h"
#include "func.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
#define PINMUX_BASE 0x03001000
#define INVALID_PIN 9999

struct pinlist {
	char name[32];
	uint32_t offset;
} pinlist_st;

struct pinlist cv181x_pin[] = {
	{ "GP0", 0x70 },		// IIC0_SCL
	{ "GP1", 0x74 },		// IIC0_SDA
	{ "GP2", 0x64 },		// JTAG_CPU_TMS
	{ "GP3", 0x68 },		// JTAG_CPU_TCK
	{ "GP4", 0xd4 },		// SD1_D2
	{ "GP5", 0xd8 },		// SD1_D1
	{ "GP6", 0xe4 },		// SD1_CLK
	{ "GP7", 0xe0 },		// SD1_CMD
	{ "GP8", 0xdc },		// SD1_D0
	{ "GP9", 0xd0 },		// SD1_D3
	{ "GP10", 0x1ac },		// PAD_MIPI_TXM1
	{ "GP11", 0x1b0 },		// PAD_MIPI_TXP1
	{ "GP12", 0x40 },		// UART0_TX
	{ "GP13", 0x44 },		// UART0_RX
	{ "GP14", 0x38 },		// SD0_PWR_EN
	{ "GP15", 0x3c },		// SPK_EN
	{ "GP16", 0x5c },		// EMMC_CMD
	{ "GP17", 0x60 },		// EMMC_DAT1
	{ "GP18", 0x50 },		// EMMC_CLK
	{ "GP19", 0x54 },		// EMMC_DAT0
	{ "GP20", 0x58 },		// EMMC_DAT3
	{ "GP21", 0x4c },		// EMMC_DAT2
	{ "GP22", 0x88 },		// PWR_SEQ2
	{ "GP26", 0xf8 },		// ADC1
	{ "GP27", 0x108 },		// USB_VBUS_DET

	{ "GP25", 0xac },		// PWR_GPIO2
};

uint32_t convert_func_to_value(char *pin, char *func)
{
	uint32_t i = 0;
	uint32_t max_fun_num = NELEMS(cv181x_pin_func);
	char v;

	for (i = 0; i < max_fun_num; i++) {
		if (strcmp(cv181x_pin_func[i].func, func) == 0) {
			if (strncmp(cv181x_pin_func[i].name, pin, strlen(pin)) == 0) {
				v = cv181x_pin_func[i].name[strlen(cv181x_pin_func[i].name) - 1];
				break;
			}
		}
	}

	if (i == max_fun_num) {
		printf("ERROR: invalid pin or func\n");
		return INVALID_PIN;
	}

	return (v - 0x30);
}

void print_fun(char *name, uint32_t value)
{
	uint32_t i = 0;
	uint32_t max_fun_num = NELEMS(cv181x_pin_func);
	char pinname[128];

	sprintf(pinname, "%s%d", name, value);

	printf("%s function:\n", name);
	for (i = 0; i < max_fun_num; i++) {
		if (strlen(cv181x_pin_func[i].name) != (strlen(name) + 1)) {
			continue;
		}
		if (strncmp(pinname, cv181x_pin_func[i].name, strlen(name)) == 0) {
			if (strcmp(pinname, cv181x_pin_func[i].name) == 0)
				printf("[v] %s\n", cv181x_pin_func[i].func);
			else
				printf("[ ] %s\n", cv181x_pin_func[i].func);
			// break;
		}
	}
	printf("\n");
}

void print_usage(const char *prog)
{
	printf("pinmux for duo256m\n");
	printf("%s -p          <== List all pins\n", prog);
	printf("%s -l          <== List all pins and its func\n", prog);
	printf("%s -r pin      <== Get func from pin\n", prog);
	printf("%s -w pin/func <== Set func to pin\n", prog);
}

int main(int argc, char *argv[])
{
	int opt = 0;
	uint32_t i = 0;
	uint32_t value;
	char pin[32];
	char func[32];
	uint32_t f_val;

	if (argc == 1) {
		print_usage(argv[0]);
		return 1;
	}

	while ((opt = getopt(argc, argv, "hplr:w:")) != -1) {
		switch (opt) {
		case 'r':
			for (i = 0; i < NELEMS(cv181x_pin); i++) {
				if (strcmp(optarg, cv181x_pin[i].name) == 0)
					break;
			}
			if (i != NELEMS(cv181x_pin)) {
				value = devmem_readl(PINMUX_BASE + cv181x_pin[i].offset);
				// printf("value %d\n", value);
				print_fun(optarg, value);

				printf("register: 0x%x\n", PINMUX_BASE + cv181x_pin[i].offset);
				printf("value: %d\n", value);
			} else {
				printf("\nInvalid option: %s", optarg);
			}
			break;

		case 'w':
			// printf("optarg %s\n", optarg);
			if (sscanf(optarg, "%[^/]/%s", pin, func) != 2)
				print_usage(argv[0]);

			printf("pin %s\n", pin);
			printf("func %s\n", func);

			for (i = 0; i < NELEMS(cv181x_pin); i++) {
				if (strcmp(pin, cv181x_pin[i].name) == 0)
					break;
			}

			if (i != NELEMS(cv181x_pin)) {
				f_val = convert_func_to_value(pin, func);
				if (f_val == INVALID_PIN)
					return 1;
				devmem_writel(PINMUX_BASE + cv181x_pin[i].offset, f_val);

				printf("register: %x\n", PINMUX_BASE + cv181x_pin[i].offset);
				printf("value: %d\n", f_val);
				// printf("value %d\n", value);
			} else {
				printf("\nInvalid option: %s\n", optarg);
			}
			break;

		case 'p':
			printf("Pinlist:\n");
			for (i = 0; i < NELEMS(cv181x_pin); i++)
				printf("%s\n", cv181x_pin[i].name);
			break;

		case 'l':
			for (i = 0; i < NELEMS(cv181x_pin); i++) {
				value = devmem_readl(PINMUX_BASE + cv181x_pin[i].offset);
				// printf("value %d\n", value);
				print_fun(cv181x_pin[i].name, value);
			}
			break;

		case 'h':
			print_usage(argv[0]);
			break;

		case '?':
			print_usage(argv[0]);
			break;

		default:
			print_usage(argv[0]);
			break;
		}
	}

	return 0;
}
