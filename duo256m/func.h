struct funlist {
	char name[32];
	char func[32];
} funlist_st;

struct funlist cv181x_pin_func[] = {
	// GP0 IIC0_SCL
	{ "GP00", "CV_SCL0"},
	{ "GP01", "UART1_TX"},
	{ "GP02", "UART2_TX"},
	{ "GP03", "GP0"},
	{ "GP05", "WG0_D0"},
	{ "GP07", "DBG_10"},

	// GP1 IIC0_SDA
	{ "GP10", "CV_SDA0"},
	{ "GP11", "UART1_RX"},
	{ "GP12", "UART2_RX"},
	{ "GP13", "GP1"},
	{ "GP15", "WG0_D1"},
	{ "GP16", "WG1_D0"},
	{ "GP17", "DBG_11"},

	// GP2 JTAG_CPU_TMS
	{ "GP20", "CV_2WTMS_CR_4WTMS"},
	{ "GP21", "CAM_MCLK0"},
	{ "GP22", "PWM_7"},
	{ "GP23", "GP2"},
	{ "GP24", "UART1_RTS"},
	{ "GP25", "AUX0"},
	{ "GP26", "UART1_TX"},
	{ "GP27", "VO_D_28"},

	// GP3 JTAG_CPU_TCK
	{ "GP30", "CV_2WTCK_CR_4WTCK"},
	{ "GP31", "CAM_MCLK1"},
	{ "GP32", "PWM_6"},
	{ "GP33", "GP3"},
	{ "GP34", "UART1_CTS"},
	{ "GP35", "AUX1"},
	{ "GP36", "UART1_RX"},
	{ "GP37", "VO_D_29"},

	// GP4 SD1_D2
	{ "GP40", "PWR_SD1_D2_VO33"},
	{ "GP41", "IIC1_SCL"},
	{ "GP42", "UART2_TX"},
	{ "GP43", "GP4"},
	{ "GP44", "CAM_MCLK0"},
	{ "GP45", "UART3_TX"},
	{ "GP46", "PWR_SPINOR1_HOLD_X"},
	{ "GP47", "PWM_5"},

	// GP5 SD1_D1
	{ "GP50", "PWR_SD1_D1_VO34"},
	{ "GP51", "IIC1_SDA"},
	{ "GP52", "UART2_RX"},
	{ "GP53", "GP5"},
	{ "GP54", "CAM_MCLK1"},
	{ "GP55", "UART3_RX"},
	{ "GP56", "PWR_SPINOR1_WP_X"},
	{ "GP57", "PWM_6"},

	// GP6 SD1_CLK
	{ "GP60", "PWR_SD1_CLK_VO37"},
	{ "GP61", "SPI2_SCK"},
	{ "GP62", "IIC3_SDA"},
	{ "GP63", "GP6"},
	{ "GP64", "CAM_HS0"},
	{ "GP65", "EPHY_SPD_LED"},
	{ "GP66", "PWR_SPINOR1_SCK"},
	{ "GP67", "PWM_9"},

	// GP7 SD1_CMD
	{ "GP70", "PWR_SD1_CMD_VO36"},
	{ "GP71", "SPI2_SDO"},
	{ "GP72", "IIC3_SCL"},
	{ "GP73", "GP7"},
	{ "GP74", "CAM_VS0"},
	{ "GP75", "EPHY_LNK_LED"},
	{ "GP76", "PWR_SPINOR1_MOSI"},
	{ "GP77", "PWM_8"},

	// GP8 SD1_D0
	{ "GP80", "PWR_SD1_D0_VO35"},
	{ "GP81", "SPI2_SDI"},
	{ "GP82", "IIC1_SDA"},
	{ "GP83", "GP8"},
	{ "GP84", "CAM_MCLK1"},
	{ "GP85", "UART3_RTS"},
	{ "GP86", "PWR_SPINOR1_MISO"},
	{ "GP87", "PWM_7"},

	// GP9 SD1_D3
	{ "GP90", "PWR_SD1_D3_VO32"},
	{ "GP91", "SPI2_CS_X"},
	{ "GP92", "IIC1_SCL"},
	{ "GP93", "GP9"},
	{ "GP94", "CAM_MCLK0"},
	{ "GP95", "UART3_CTS"},
	{ "GP96", "PWR_SPINOR1_CS_X"},
	{ "GP97", "PWM_4"},

	// GP10 PAD_MIPI_TXM1
	{ "GP100", "CV_4WTDO_CR_2WTMS"},
	{ "GP101", "VI0_D_11"},
	{ "GP102", "VO_D_2"},
	{ "GP103", "GP10"},
	{ "GP104", "IIC2_SDA"},
	{ "GP105", "PWM_10"},
	{ "GP106", "SPI0_SDO"},
	{ "GP107", "DBG_14"},

	// GP11 PAD_MIPI_TXP1
	{ "GP110", "CV_4WTCK_CR_2WTCK"},
	{ "GP111", "VI0_D_12"},
	{ "GP112", "VO_D_1"},
	{ "GP113", "GP11"},
	{ "GP114", "IIC2_SCL"},
	{ "GP115", "PWM_11"},
	{ "GP116", "SPI0_SDI"},
	{ "GP117", "DBG_15"},

	// GP12 UART0_TX
	{ "GP120", "UART0_TX"},
	{ "GP121", "CAM_MCLK1"},
	{ "GP122", "PWM_4"},
	{ "GP123", "GP12"},
	{ "GP124", "UART1_TX"},
	{ "GP125", "AUX1"},
	{ "GP127", "DBG_6"},

	// GP13 UART0_RX
	{ "GP130", "UART0_RX"},
	{ "GP131", "CAM_MCLK0"},
	{ "GP132", "PWM_5"},
	{ "GP133", "GP13"},
	{ "GP134", "UART1_RX"},
	{ "GP135", "AUX0"},
	{ "GP137", "DBG_7"},

	// GP14 SD0_PWR_EN
	{ "GP140", "SDIO0_PWR_EN"},
	{ "GP143", "GP14"},

	// GP15 SPK_EN
	{ "GP153", "GP15"},

	// GP16 EMMC_CMD
	{ "GP160", "EMMC_CMD"},
	{ "GP161", "SPINOR_MISO"},
	{ "GP162", "SPINAND_MISO"},
	{ "GP163", "GP16"},

	// GP17 EMMC_DAT1
	{ "GP170", "EMMC_DAT_1"},
	{ "GP171", "SPINOR_CS_X"},
	{ "GP172", "SPINAND_CS"},
	{ "GP173", "GP17"},

	// GP18 EMMC_CLK
	{ "GP180", "EMMC_CLK"},
	{ "GP181", "SPINOR_SCK"},
	{ "GP182", "SPINAND_CLK"},
	{ "GP183", "GP18"},

	// GP19 EMMC_DAT0
	{ "GP190", "EMMC_DAT_0"},
	{ "GP191", "SPINOR_MOSI"},
	{ "GP192", "SPINAND_MOSI"},
	{ "GP193", "GP19"},

	// GP20 EMMC_DAT3
	{ "GP200", "EMMC_DAT_3"},
	{ "GP201", "SPINOR_WP_X"},
	{ "GP202", "SPINAND_WP"},
	{ "GP203", "GP20"},

	// GP21 EMMC_DAT2
	{ "GP210", "EMMC_DAT_2"},
	{ "GP211", "SPINOR_HOLD_X"},
	{ "GP212", "SPINAND_HOLD"},
	{ "GP213", "GP21"},

	// GP22 PWR_SEQ2
	{ "GP220", "PWR_SEQ2"},
	{ "GP223", "GP22"},

	// GP25 PWR_GPIO2
	{ "GP250", "GP25"},
	{ "GP252", "PWR_SECTICK"},
	{ "GP253", "EPHY_SPD_LED"},
	{ "GP254", "PWM_10"},
	{ "GP255", "PWR_IIC_SDA"},
	{ "GP256", "IIC2_SDA"},
	{ "GP257", "CV_4WTCK_CR_2WTCK"},

	// GP26 ADC1
	{ "GP263", "GP26"},
	{ "GP264", "KEY_COL2"},

	// GP27 USB_VBUS_DET
	{ "GP270", "USB_VBUS_DET"},
	{ "GP273", "GP27"},
	{ "GP274", "CAM_MCLK0"},
	{ "GP275", "CAM_MCLK1"},
};
