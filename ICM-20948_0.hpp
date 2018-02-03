/*
 * name:        ICM-20948
 * description: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications.
 * manuf:       TDK Invensense
 * version:     Version 0.1
 * url:         https://www.invensense.com/wp-content/uploads/2016/06/DS-000189-ICM-20948-v1.3.pdf
 * date:        2017-10-18
 * author       https://chisl.io/
 * file:        ICM-20948_0.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class ICM_20948_0_Base and implement the read and write functions! */

/* ICM-20948: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications. */
class ICM_20948_0_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG WHO_AM_I                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG WHO_AM_I:
	 * type USR0, bank 0
	 */
	struct WHO_AM_I
	{
		static const uint16_t __address = 0;
		
		/* Bits WHO_AM_I: */
		/*
		 * Register to indicate to user which device is being accessed.
		 * The value for ICM-20948 is 0xEA.
		 */
		struct WHO_AM_I_
		{
			/* MODE r */
			static const uint8_t dflt = 0b11101010; // 8'b11101010
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register WHO_AM_I */
	void setWHO_AM_I(uint8_t value)
	{
		write(WHO_AM_I::__address, value, 8);
	}
	
	/* Get register WHO_AM_I */
	uint8_t getWHO_AM_I()
	{
		return read8(WHO_AM_I::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG USER_CTRL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG USER_CTRL:
	 * type USR0, bank 0
	 */
	struct USER_CTRL
	{
		static const uint16_t __address = 3;
		
		/* Bits DMP_EN: */
		struct DMP_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t ENABLE_DMP = 0b1; // 1 - Enables DMP features.
			static const uint8_t DISABLE_DMP = 0b0; // 0 - DMP features are disabled after the current processing round has completed.
		};
		/* Bits FIFO_EN: */
		/*
		 * To disable FIFO writes by DMA, use FIFO_EN register. To disable possible FIFO writes
		 * from DMP, disable the DMP.
		 */
		struct FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t ENABLE_FIFO = 0b1; // 1 - Enable FIFO operation mode.
			static const uint8_t DISABLE_FIFO = 0b0; // 0 - Disable FIFO access from serial interface.
		};
		/* Bits I2C_MST_EN: */
		struct I2C_MST_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t ENABLE = 0b1; // 1 - Enable the I2C Master I/F module; pins ES_DA and ES_SCL are isolated from pins SDA/SDI and SCL/ SCLK.
			static const uint8_t DISABLE = 0b0; // 0 - Disable I2C Master I/F module; pins ES_DA and ES_SCL are logically driven by pins SDA/SDI and SCL/ SCLK.
		};
		/* Bits I2C_IF_DIS: */
		struct I2C_IF_DIS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t RESET = 0b1; // 1 - Reset I2C Slave module and put the serial interface in SPI mode only.
		};
		/* Bits DMP_RST: */
		struct DMP_RST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t RESET = 0b1; // 1 - Reset DMP module. Reset is asynchronous. This bit auto clears after one clock cycle of the internal 20 MHz clock.
		};
		/* Bits SRAM_RST: */
		struct SRAM_RST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t RESET_SRAM = 0b1; // 1 - Reset SRAM module. Reset is asynchronous. This bit auto clears after one clock cycle of the internal 20 MHz clock. §
		};
		/* Bits I2C_MST_RST: */
		/*
		 * 1 - Reset I2C Master module. Reset is asynchronous. This bit auto clears after one
		 * clock cycle of the internal 20 MHz clock.
		 * NOTE: This bit should only be set when the I2C master has hung. If this bit is set during an active
		 * I2C master transaction, the I2C slave will hang, which will require the host to reset the slave.
		 */
		struct I2C_MST_RST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t RESET_I2C_MASTER = 0b1; // 
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register USER_CTRL */
	void setUSER_CTRL(uint8_t value)
	{
		write(USER_CTRL::__address, value, 8);
	}
	
	/* Get register USER_CTRL */
	uint8_t getUSER_CTRL()
	{
		return read8(USER_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG LP_CONFIG                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG LP_CONFIG:
	 * type USR0, bank 0
	 */
	struct LP_CONFIG
	{
		static const uint16_t __address = 5;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_MST_CYCLE: */
		/*
		 * 1 - Operate I2C master in duty cycled mode. ODR is determined by
		 * I2C_MST_ODR_CONFIG register.
		 * 0 - Disable I2C master duty cycled mode.
		 */
		struct I2C_MST_CYCLE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits ACCEL_CYCLE: */
		/*
		 * 1 - Operate ACCEL in duty cycled mode. ODR is determined by ACCEL_SMPLRT_DIV
		 * register.
		 * 0 - Disable ACCEL duty cycled mode.
		 */
		struct ACCEL_CYCLE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits GYRO_CYCLE: */
		/*
		 * 1 - Operate GYRO in duty cycled mode. ODR is determined by GYRO_SMPLRT_DIV
		 * register.
		 * 0 - Disable GYRO duty cycled mode.
		 */
		struct GYRO_CYCLE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits reserved_1: */
		struct reserved_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register LP_CONFIG */
	void setLP_CONFIG(uint8_t value)
	{
		write(LP_CONFIG::__address, value, 8);
	}
	
	/* Get register LP_CONFIG */
	uint8_t getLP_CONFIG()
	{
		return read8(LP_CONFIG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PWR_MGMT_1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG PWR_MGMT_1:
	 * type USR0, bank 0
	 */
	struct PWR_MGMT_1
	{
		static const uint16_t __address = 6;
		
		/* Bits DEVICE_RESET: */
		/*
		 * 1 - Reset the internal registers and restores the default settings. Write a 1 to set the
		 * reset, the bit will auto clear.
		 */
		struct DEVICE_RESET
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits SLEEP: */
		/*
		 * When set, the chip is set to sleep mode (in sleep mode all analog is powered off).
		 * Clearing the bit wakes the chip from sleep mode.
		 */
		struct SLEEP
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits LP_EN: */
		/*
		 * The LP_EN only affects the digital circuitry, it helps to reduce the digital current when
		 * sensors are in LP mode. Please note that the sensors themselves are set in LP mode
		 * by the LP_CONFIG register settings. Sensors in LP mode, and use of LP_EN bit
		 * together help to reduce overall current. The bit settings are:
		 * 1: Turn on low power feature.
		 * 0: Turn off low power feature.
		 * LP_EN has no effect when the sensors are in low-noise mode.
		 */
		struct LP_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits TEMP_DIS: */
		/* When set to 1, this bit disables the temperature sensor.  */
		struct TEMP_DIS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits CLKSEL: */
		/*
		 * Code: Clock Source
		 * 0: Internal 20 MHz oscillator
		 * 1-5: Auto selects the best available clock source - PLL if ready, else use the Internal oscillator
		 * 6: Internal 20 MHz oscillator
		 * 7: Stops the clock and keeps timing generator in reset
		 * NOTE: CLKSEL[2:0] should be set to 1~5 to achieve full gyroscope performance.
		 */
		struct CLKSEL
		{
			/* MODE rw */
			static const uint8_t dflt = 0b001; // 3'b1
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register PWR_MGMT_1 */
	void setPWR_MGMT_1(uint8_t value)
	{
		write(PWR_MGMT_1::__address, value, 8);
	}
	
	/* Get register PWR_MGMT_1 */
	uint8_t getPWR_MGMT_1()
	{
		return read8(PWR_MGMT_1::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PWR_MGMT_2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG PWR_MGMT_2:
	 * type USR0, bank 0
	 */
	struct PWR_MGMT_2
	{
		static const uint16_t __address = 7;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits DISABLE_ACCEL: */
		/*
		 * Only the following values are applicable:
		 * 111 - Accelerometer (all axes) disabled.
		 * 000 - Accelerometer (all axes) on.
		 */
		struct DISABLE_ACCEL
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00111000; // [3,4,5]
		};
		/* Bits DISABLE_GYRO: */
		/*
		 * Only the following values are applicable:
		 * 111 - Gyroscope (all axes) disabled.
		 * 000 - Gyroscope (all axes) on.
		 */
		struct DISABLE_GYRO
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register PWR_MGMT_2 */
	void setPWR_MGMT_2(uint8_t value)
	{
		write(PWR_MGMT_2::__address, value, 8);
	}
	
	/* Get register PWR_MGMT_2 */
	uint8_t getPWR_MGMT_2()
	{
		return read8(PWR_MGMT_2::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG INT_PIN_CFG                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT_PIN_CFG:
	 * type USR0, bank 0
	 */
	struct INT_PIN_CFG
	{
		static const uint16_t __address = 15;
		
		/* Bits INT1_ACTL: */
		/*
		 * 1 - The logic level for INT1 pin is active low.
		 * 0 - The logic level for INT1 pin is active high.
		 */
		struct INT1_ACTL
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits INT1_OPEN: */
		/*
		 * 1 - INT1 pin is configured as open drain.
		 * 0 - INT1 pin is configured as push-pull.
		 */
		struct INT1_OPEN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits INT1_LATCH_EN: */
		/*
		 * 1 - INT1 pin level held until interrupt status is cleared.
		 * 0 - INT1 pin indicates interrupt pulse is width 50 µs.
		 */
		struct INT1_LATCH_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits INT_ANYRD_2CLEAR: */
		/*
		 * 1 - Interrupt status in INT_STATUS is cleared (set to 0) if any read operation is
		 * performed.
		 * 0 - Interrupt status in INT_STATUS is cleared (set to 0) only by reading INT_STATUS
		 * register.
		 * This bit only affects the interrupt status bits that are contained in the register
		 * INT_STATUS, and the corresponding hardware interrupt.
		 * This bit does not affect the interrupt status bits that are contained in registers
		 * INT_STATUS_1, INT_STATUS_2, INT_STATUS_3, and the corresponding hardware
		 * interrupt.
		 */
		struct INT_ANYRD_2CLEAR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits ACTL_FSYNC: */
		/*
		 * 1 - The logic level for the FSYNC pin as an interrupt to the ICM-20948 is active low.
		 * 0 - The logic level for the FSYNC pin as an interrupt to the ICM-20948 is active high.
		 */
		struct ACTL_FSYNC
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits FSYNC_INT_MODE_EN: */
		/*
		 * 1 - This enables the FSYNC pin to be used as an interrupt. A transition to the active
		 * level described by the ACTL_FSYNC bit will cause an interrupt. The status of the
		 * interrupt is read in the I2C Master Status register PASS_THROUGH bit.
		 * 0 - This disables the FSYNC pin from causing an interrupt.
		 */
		struct FSYNC_INT_MODE_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits BYPASS_EN: */
		/*
		 * When asserted, the I2C_MASTER interface pins (ES_CL and ES_DA) will go into
		 * ‘bypass mode’ when the I2C master interface is disabled.
		 */
		struct BYPASS_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_PIN_CFG */
	void setINT_PIN_CFG(uint8_t value)
	{
		write(INT_PIN_CFG::__address, value, 8);
	}
	
	/* Get register INT_PIN_CFG */
	uint8_t getINT_PIN_CFG()
	{
		return read8(INT_PIN_CFG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG INT_ENABLE                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_ENABLE:
	 * type USR0, bank 0
	 */
	struct INT_ENABLE
	{
		static const uint16_t __address = 16;
		
		/* Bits REG_WOF_EN: */
		/*
		 * 1 - Enable wake on FSYNC interrupt.
		 * 0 - Function is disabled.
		 */
		struct REG_WOF_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b01110000; // [4,5,6]
		};
		/* Bits WOM_INT_EN: */
		/*
		 * 1 - Enable interrupt for wake on motion to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct WOM_INT_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits PLL_RDY_EN: */
		/*
		 * 1 - Enable PLL RDY interrupt (PLL RDY means PLL is running and in use as the clock
		 * source for the system) to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct PLL_RDY_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits DMP_INT1_EN: */
		/*
		 * 1 - Enable DMP interrupt to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct DMP_INT1_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits I2C_MST_INT_EN: */
		/*
		 * 1 - Enable I2C master interrupt to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct I2C_MST_INT_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_ENABLE */
	void setINT_ENABLE(uint8_t value)
	{
		write(INT_ENABLE::__address, value, 8);
	}
	
	/* Get register INT_ENABLE */
	uint8_t getINT_ENABLE()
	{
		return read8(INT_ENABLE::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_ENABLE_1                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_ENABLE_1:
	 * type USR0, bank 0
	 */
	struct INT_ENABLE_1
	{
		static const uint16_t __address = 17;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits RAW_DATA_0_RDY_EN: */
		/*
		 * 1 - Enable raw data ready interrupt from any sensor to propagate to interrupt
		 * pin 1.
		 * 0 - Function is disabled.
		 */
		struct RAW_DATA_0_RDY_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_ENABLE_1 */
	void setINT_ENABLE_1(uint8_t value)
	{
		write(INT_ENABLE_1::__address, value, 8);
	}
	
	/* Get register INT_ENABLE_1 */
	uint8_t getINT_ENABLE_1()
	{
		return read8(INT_ENABLE_1::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_ENABLE_2                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_ENABLE_2:
	 * type USR0, bank 0
	 */
	struct INT_ENABLE_2
	{
		static const uint16_t __address = 18;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_OVERFLOW_EN: */
		/*
		 * 1 - Enable interrupt for FIFO overflow to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct FIFO_OVERFLOW_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register INT_ENABLE_2 */
	void setINT_ENABLE_2(uint8_t value)
	{
		write(INT_ENABLE_2::__address, value, 8);
	}
	
	/* Get register INT_ENABLE_2 */
	uint8_t getINT_ENABLE_2()
	{
		return read8(INT_ENABLE_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_ENABLE_3                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_ENABLE_3:
	 * type USR0, bank 0
	 */
	struct INT_ENABLE_3
	{
		static const uint16_t __address = 19;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_WM_EN: */
		/*
		 * 1 - Enable interrupt for FIFO watermark to propagate to interrupt pin 1.
		 * 0 - Function is disabled.
		 */
		struct FIFO_WM_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register INT_ENABLE_3 */
	void setINT_ENABLE_3(uint8_t value)
	{
		write(INT_ENABLE_3::__address, value, 8);
	}
	
	/* Get register INT_ENABLE_3 */
	uint8_t getINT_ENABLE_3()
	{
		return read8(INT_ENABLE_3::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG I2C_MST_STATUS                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_MST_STATUS:
	 * type USR0, bank 0
	 */
	struct I2C_MST_STATUS
	{
		static const uint16_t __address = 23;
		
		/* Bits PASS_THROUGH: */
		/*
		 * Status of FSYNC interrupt - used as a way to pass an external interrupt through this
		 * chip to the host.  If enabled in the INT_PIN_CFG register by asserting bit
		 * FSYNC_INT_MODE_EN, this will cause an interrupt.  A read of this register clears all
		 * status bits in this register.
		 */
		struct PASS_THROUGH
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV4_DONE: */
		/*
		 * Asserted when I2C slave 4’s transfer is complete, will cause an interrupt if bit
		 * I2C_MST_INT_EN in the INT_ENABLE register is asserted, and if the
		 * SLV4_DONE_INT_EN bit is asserted in the I2C_SLV4_CTRL register.
		 */
		struct I2C_SLV4_DONE
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_LOST_ARB: */
		/*
		 * Asserted when I2C slave loses arbitration of the I2C bus, will cause an interrupt if bit
		 * I2C_MST_INT_EN in the INT_ENABLE register is asserted.
		 */
		struct I2C_LOST_ARB
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV4_NACK: */
		/*
		 * Asserted when slave 4 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN
		 * in the INT_ENABLE register is asserted.
		 */
		struct I2C_SLV4_NACK
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV3_NACK: */
		/*
		 * Asserted when slave 3 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN
		 * in the INT_ENABLE register is asserted.
		 */
		struct I2C_SLV3_NACK
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits I2C_SLV2_NACK: */
		/*
		 * Asserted when slave 2 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN
		 * in the INT_ENABLE register is asserted.
		 */
		struct I2C_SLV2_NACK
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits I2C_SLV1_NACK: */
		/*
		 * Asserted when slave 1 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN
		 * in the INT_ENABLE register is asserted.
		 */
		struct I2C_SLV1_NACK
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits I2C_SLV0_NACK: */
		/*
		 * Asserted when slave 0 receives a NACK, will cause an interrupt if bit I2C_MST_INT_EN
		 * in the INT_ENABLE register is asserted.
		 */
		struct I2C_SLV0_NACK
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register I2C_MST_STATUS */
	void setI2C_MST_STATUS(uint8_t value)
	{
		write(I2C_MST_STATUS::__address, value, 8);
	}
	
	/* Get register I2C_MST_STATUS */
	uint8_t getI2C_MST_STATUS()
	{
		return read8(I2C_MST_STATUS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG INT_STATUS                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_STATUS:
	 * type USR0, bank 0
	 */
	struct INT_STATUS
	{
		static const uint16_t __address = 25;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits WOM_INT: */
		/* 1 - Wake on motion interrupt occurred.  */
		struct WOM_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits PLL_RDY_INT: */
		/* 1 - Indicates that the PLL has been enabled and is ready (delay of 4 ms ensures lock).  */
		struct PLL_RDY_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits DMP_INT1: */
		/* 1 - Indicates the DMP has generated INT1 interrupt.  */
		struct DMP_INT1
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits I2C_MST_INT: */
		/* 1 - Indicates I2C master has generated an interrupt.  */
		struct I2C_MST_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_STATUS */
	void setINT_STATUS(uint8_t value)
	{
		write(INT_STATUS::__address, value, 8);
	}
	
	/* Get register INT_STATUS */
	uint8_t getINT_STATUS()
	{
		return read8(INT_STATUS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_STATUS_1                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_STATUS_1:
	 * type USR0, bank 0
	 */
	struct INT_STATUS_1
	{
		static const uint16_t __address = 26;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits RAW_DATA_0_RDY_INT: */
		/* 1 - Sensor Register Raw Data, from all sensors, is updated and ready to be read.  */
		struct RAW_DATA_0_RDY_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_STATUS_1 */
	void setINT_STATUS_1(uint8_t value)
	{
		write(INT_STATUS_1::__address, value, 8);
	}
	
	/* Get register INT_STATUS_1 */
	uint8_t getINT_STATUS_1()
	{
		return read8(INT_STATUS_1::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_STATUS_2                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_STATUS_2:
	 * type USR0, bank 0
	 */
	struct INT_STATUS_2
	{
		static const uint16_t __address = 27;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rc */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_OVERFLOW_INT: */
		/* 1 - FIFO Overflow interrupt occurred.  */
		struct FIFO_OVERFLOW_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register INT_STATUS_2 */
	void setINT_STATUS_2(uint8_t value)
	{
		write(INT_STATUS_2::__address, value, 8);
	}
	
	/* Get register INT_STATUS_2 */
	uint8_t getINT_STATUS_2()
	{
		return read8(INT_STATUS_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG INT_STATUS_3                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_STATUS_3:
	 * type USR0, bank 0
	 */
	struct INT_STATUS_3
	{
		static const uint16_t __address = 28;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rc */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_WM_INT: */
		/* 1 - Watermark interrupt for FIFO occurred.  */
		struct FIFO_WM_INT
		{
			/* MODE rc */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register INT_STATUS_3 */
	void setINT_STATUS_3(uint8_t value)
	{
		write(INT_STATUS_3::__address, value, 8);
	}
	
	/* Get register INT_STATUS_3 */
	uint8_t getINT_STATUS_3()
	{
		return read8(INT_STATUS_3::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG DELAY_TIMEH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DELAY_TIMEH:
	 * type USR0, bank 0
	 */
	struct DELAY_TIMEH
	{
		static const uint16_t __address = 40;
		
		/* Bits DELAY_TIMEH: */
		/*
		 * High-byte of delay time between FSYNC event and the 1st gyro ODR event (after the
		 * FSYNC event).
		 * Reading DELAY_TIMEH will lock DELAY_TIMEH and DELAY_TIMEL from the next
		 * update.  Reading DELAY_TIMEL will unlock DELAY_TIMEH and DELAY_TIMEL to take
		 * the next update due to an FSYNC event.
		 */
		struct DELAY_TIMEH_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DELAY_TIMEH */
	void setDELAY_TIMEH(uint8_t value)
	{
		write(DELAY_TIMEH::__address, value, 8);
	}
	
	/* Get register DELAY_TIMEH */
	uint8_t getDELAY_TIMEH()
	{
		return read8(DELAY_TIMEH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG DELAY_TIMEL                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DELAY_TIMEL:
	 * type USR0, bank 0
	 */
	struct DELAY_TIMEL
	{
		static const uint16_t __address = 41;
		
		/* Bits DELAY_TIMEL: */
		/*
		 * Low-byte of delay time between FSYNC event and the 1st gyro ODR event (after the
		 * FSYNC event).
		 * Reading DELAY_TIMEH will lock DELAY_TIMEH and DELAY_TIMEL from the next
		 * update. Reading DELAY_TIMEL will unlock DELAY_TIMEH and DELAY_TIMEL to take
		 * the next update due to an FSYNC event.
		 * Delay time in µs = (DELAY_TIMEH * 256 +  DELAY_TIMEL) * 0.9645
		 */
		struct DELAY_TIMEL_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DELAY_TIMEL */
	void setDELAY_TIMEL(uint8_t value)
	{
		write(DELAY_TIMEL::__address, value, 8);
	}
	
	/* Get register DELAY_TIMEL */
	uint8_t getDELAY_TIMEL()
	{
		return read8(DELAY_TIMEL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_XOUT_H                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_XOUT_H:
	 * type USR0, bank 0
	 */
	struct ACCEL_XOUT_H
	{
		static const uint16_t __address = 45;
		
		/* Bits ACCEL_XOUT_H: */
		/* High Byte of Accelerometer X-axis data.  */
		struct ACCEL_XOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_XOUT_H */
	void setACCEL_XOUT_H(uint8_t value)
	{
		write(ACCEL_XOUT_H::__address, value, 8);
	}
	
	/* Get register ACCEL_XOUT_H */
	uint8_t getACCEL_XOUT_H()
	{
		return read8(ACCEL_XOUT_H::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_XOUT_L                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_XOUT_L:
	 * type USR0, bank 0
	 */
	struct ACCEL_XOUT_L
	{
		static const uint16_t __address = 46;
		
		/* Bits ACCEL_XOUT_L: */
		/*
		 * Low Byte of Accelerometer X-axis data.
		 * To convert the output of the accelerometer to acceleration measurement use the
		 * formula below:
		 * X_acceleration = ACCEL_XOUT/Accel_Sensitivity
		 */
		struct ACCEL_XOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_XOUT_L */
	void setACCEL_XOUT_L(uint8_t value)
	{
		write(ACCEL_XOUT_L::__address, value, 8);
	}
	
	/* Get register ACCEL_XOUT_L */
	uint8_t getACCEL_XOUT_L()
	{
		return read8(ACCEL_XOUT_L::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_YOUT_H                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_YOUT_H:
	 * type USR0, bank 0
	 */
	struct ACCEL_YOUT_H
	{
		static const uint16_t __address = 47;
		
		/* Bits ACCEL_YOUT_H: */
		/* High Byte of Accelerometer Y-axis data.  */
		struct ACCEL_YOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_YOUT_H */
	void setACCEL_YOUT_H(uint8_t value)
	{
		write(ACCEL_YOUT_H::__address, value, 8);
	}
	
	/* Get register ACCEL_YOUT_H */
	uint8_t getACCEL_YOUT_H()
	{
		return read8(ACCEL_YOUT_H::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_YOUT_L                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_YOUT_L:
	 * type USR0, bank 0
	 */
	struct ACCEL_YOUT_L
	{
		static const uint16_t __address = 48;
		
		/* Bits ACCEL_YOUT_L: */
		/*
		 * Low Byte of Accelerometer Y-axis data.
		 * To convert the output of the accelerometer to acceleration measurement use the
		 * formula below:
		 * Y_acceleration = ACCEL_YOUT/Accel_Sensitivity
		 */
		struct ACCEL_YOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_YOUT_L */
	void setACCEL_YOUT_L(uint8_t value)
	{
		write(ACCEL_YOUT_L::__address, value, 8);
	}
	
	/* Get register ACCEL_YOUT_L */
	uint8_t getACCEL_YOUT_L()
	{
		return read8(ACCEL_YOUT_L::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_ZOUT_H                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_ZOUT_H:
	 * type USR0, bank 0
	 */
	struct ACCEL_ZOUT_H
	{
		static const uint16_t __address = 49;
		
		/* Bits ACCEL_ZOUT_H: */
		/* High Byte of Accelerometer Z-axis data.  */
		struct ACCEL_ZOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_ZOUT_H */
	void setACCEL_ZOUT_H(uint8_t value)
	{
		write(ACCEL_ZOUT_H::__address, value, 8);
	}
	
	/* Get register ACCEL_ZOUT_H */
	uint8_t getACCEL_ZOUT_H()
	{
		return read8(ACCEL_ZOUT_H::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_ZOUT_L                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_ZOUT_L:
	 * type USR0, bank 0
	 */
	struct ACCEL_ZOUT_L
	{
		static const uint16_t __address = 50;
		
		/* Bits ACCEL_ZOUT_L: */
		/*
		 * Low Byte of Accelerometer Z-axis data.
		 * To convert the output of the accelerometer to acceleration measurement use the
		 * formula below:
		 * Z_acceleration = ACCEL_ZOUT/Accel_Sensitivity
		 */
		struct ACCEL_ZOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_ZOUT_L */
	void setACCEL_ZOUT_L(uint8_t value)
	{
		write(ACCEL_ZOUT_L::__address, value, 8);
	}
	
	/* Get register ACCEL_ZOUT_L */
	uint8_t getACCEL_ZOUT_L()
	{
		return read8(ACCEL_ZOUT_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_XOUT_H                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_XOUT_H:
	 * type USR0, bank 0
	 */
	struct GYRO_XOUT_H
	{
		static const uint16_t __address = 51;
		
		/* Bits GYRO_XOUT_H: */
		/* High Byte of Gyroscope X-axis data.  */
		struct GYRO_XOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_XOUT_H */
	void setGYRO_XOUT_H(uint8_t value)
	{
		write(GYRO_XOUT_H::__address, value, 8);
	}
	
	/* Get register GYRO_XOUT_H */
	uint8_t getGYRO_XOUT_H()
	{
		return read8(GYRO_XOUT_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_XOUT_L                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_XOUT_L:
	 * type USR0, bank 0
	 */
	struct GYRO_XOUT_L
	{
		static const uint16_t __address = 52;
		
		/* Bits GYRO_XOUT_L: */
		/*
		 * Low Byte of Gyroscope X-axis data.
		 * To convert the output of the gyroscope to angular rate measurement use the
		 * formula below:
		 * X_angular_rate = GYRO_XOUT/Gyro_Sensitivity
		 */
		struct GYRO_XOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_XOUT_L */
	void setGYRO_XOUT_L(uint8_t value)
	{
		write(GYRO_XOUT_L::__address, value, 8);
	}
	
	/* Get register GYRO_XOUT_L */
	uint8_t getGYRO_XOUT_L()
	{
		return read8(GYRO_XOUT_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_YOUT_H                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_YOUT_H:
	 * type USR0, bank 0
	 */
	struct GYRO_YOUT_H
	{
		static const uint16_t __address = 53;
		
		/* Bits GYRO_YOUT_H: */
		/* High Byte of Gyroscope Y-axis data.  */
		struct GYRO_YOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_YOUT_H */
	void setGYRO_YOUT_H(uint8_t value)
	{
		write(GYRO_YOUT_H::__address, value, 8);
	}
	
	/* Get register GYRO_YOUT_H */
	uint8_t getGYRO_YOUT_H()
	{
		return read8(GYRO_YOUT_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_YOUT_L                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_YOUT_L:
	 * type USR0, bank 0
	 */
	struct GYRO_YOUT_L
	{
		static const uint16_t __address = 54;
		
		/* Bits GYRO_YOUT_L: */
		/*
		 * Low Byte of Gyroscope Y-axis data.
		 * To convert the output of the gyroscope to angular rate measurement use the
		 * formula below:
		 * Y_angular_rate = GYRO_YOUT/Gyro_Sensitivity
		 */
		struct GYRO_YOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_YOUT_L */
	void setGYRO_YOUT_L(uint8_t value)
	{
		write(GYRO_YOUT_L::__address, value, 8);
	}
	
	/* Get register GYRO_YOUT_L */
	uint8_t getGYRO_YOUT_L()
	{
		return read8(GYRO_YOUT_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_ZOUT_H                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_ZOUT_H:
	 * type USR0, bank 0
	 */
	struct GYRO_ZOUT_H
	{
		static const uint16_t __address = 55;
		
		/* Bits GYRO_ZOUT_H: */
		/* High Byte of Gyroscope Z-axis data.  */
		struct GYRO_ZOUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_ZOUT_H */
	void setGYRO_ZOUT_H(uint8_t value)
	{
		write(GYRO_ZOUT_H::__address, value, 8);
	}
	
	/* Get register GYRO_ZOUT_H */
	uint8_t getGYRO_ZOUT_H()
	{
		return read8(GYRO_ZOUT_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG GYRO_ZOUT_L                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_ZOUT_L:
	 * type USR0, bank 0
	 */
	struct GYRO_ZOUT_L
	{
		static const uint16_t __address = 56;
		
		/* Bits GYRO_ZOUT_L: */
		/*
		 * Low Byte of Gyroscope Z-axis data.
		 * To convert the output of the gyroscope to angular rate measurement use the
		 * formula below:
		 * Z_angular_rate = GYRO_ZOUT/Gyro_Sensitivity
		 */
		struct GYRO_ZOUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_ZOUT_L */
	void setGYRO_ZOUT_L(uint8_t value)
	{
		write(GYRO_ZOUT_L::__address, value, 8);
	}
	
	/* Get register GYRO_ZOUT_L */
	uint8_t getGYRO_ZOUT_L()
	{
		return read8(GYRO_ZOUT_L::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG TEMP_OUT_H                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TEMP_OUT_H:
	 * type USR0, bank 0
	 */
	struct TEMP_OUT_H
	{
		static const uint16_t __address = 57;
		
		/* Bits TEMP_OUT_H: */
		/* High Byte of Temp sensor data.  */
		struct TEMP_OUT_H_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TEMP_OUT_H */
	void setTEMP_OUT_H(uint8_t value)
	{
		write(TEMP_OUT_H::__address, value, 8);
	}
	
	/* Get register TEMP_OUT_H */
	uint8_t getTEMP_OUT_H()
	{
		return read8(TEMP_OUT_H::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG TEMP_OUT_L                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TEMP_OUT_L:
	 * type USR0, bank 0
	 */
	struct TEMP_OUT_L
	{
		static const uint16_t __address = 58;
		
		/* Bits TEMP_OUT_L: */
		/*
		 * Low Byte of Temp sensor data.
		 * To convert the output of the temperature sensor to degrees C use the following
		 * formula:
		 * TEMP_degC = ((TEMP_OUT - RoomTemp_Offset)/Temp_Sensitivity) + 21degC
		 */
		struct TEMP_OUT_L_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TEMP_OUT_L */
	void setTEMP_OUT_L(uint8_t value)
	{
		write(TEMP_OUT_L::__address, value, 8);
	}
	
	/* Get register TEMP_OUT_L */
	uint8_t getTEMP_OUT_L()
	{
		return read8(TEMP_OUT_L::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_00                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_00:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_00
	{
		static const uint16_t __address = 59;
		
		/* Bits EXT_SLV_SENS_DATA_00: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_00_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_00 */
	void setEXT_SLV_SENS_DATA_00(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_00::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_00 */
	uint8_t getEXT_SLV_SENS_DATA_00()
	{
		return read8(EXT_SLV_SENS_DATA_00::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_01                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_01:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_01
	{
		static const uint16_t __address = 60;
		
		/* Bits EXT_SLV_SENS_DATA_01: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_01_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_01 */
	void setEXT_SLV_SENS_DATA_01(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_01::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_01 */
	uint8_t getEXT_SLV_SENS_DATA_01()
	{
		return read8(EXT_SLV_SENS_DATA_01::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_02                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_02:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_02
	{
		static const uint16_t __address = 61;
		
		/* Bits EXT_SLV_SENS_DATA_02: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_02_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_02 */
	void setEXT_SLV_SENS_DATA_02(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_02::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_02 */
	uint8_t getEXT_SLV_SENS_DATA_02()
	{
		return read8(EXT_SLV_SENS_DATA_02::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_03                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_03:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_03
	{
		static const uint16_t __address = 62;
		
		/* Bits EXT_SLV_SENS_DATA_03: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_03_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_03 */
	void setEXT_SLV_SENS_DATA_03(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_03::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_03 */
	uint8_t getEXT_SLV_SENS_DATA_03()
	{
		return read8(EXT_SLV_SENS_DATA_03::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_04                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_04:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_04
	{
		static const uint16_t __address = 63;
		
		/* Bits EXT_SLV_SENS_DATA_04: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_04_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_04 */
	void setEXT_SLV_SENS_DATA_04(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_04::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_04 */
	uint8_t getEXT_SLV_SENS_DATA_04()
	{
		return read8(EXT_SLV_SENS_DATA_04::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_05                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_05:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_05
	{
		static const uint16_t __address = 64;
		
		/* Bits EXT_SLV_SENS_DATA_05: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_05_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_05 */
	void setEXT_SLV_SENS_DATA_05(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_05::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_05 */
	uint8_t getEXT_SLV_SENS_DATA_05()
	{
		return read8(EXT_SLV_SENS_DATA_05::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_06                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_06:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_06
	{
		static const uint16_t __address = 65;
		
		/* Bits EXT_SLV_SENS_DATA_06: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_06_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_06 */
	void setEXT_SLV_SENS_DATA_06(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_06::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_06 */
	uint8_t getEXT_SLV_SENS_DATA_06()
	{
		return read8(EXT_SLV_SENS_DATA_06::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_07                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_07:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_07
	{
		static const uint16_t __address = 66;
		
		/* Bits EXT_SLV_SENS_DATA_07: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_07_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_07 */
	void setEXT_SLV_SENS_DATA_07(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_07::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_07 */
	uint8_t getEXT_SLV_SENS_DATA_07()
	{
		return read8(EXT_SLV_SENS_DATA_07::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_08                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_08:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_08
	{
		static const uint16_t __address = 67;
		
		/* Bits EXT_SLV_SENS_DATA_08: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_08_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_08 */
	void setEXT_SLV_SENS_DATA_08(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_08::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_08 */
	uint8_t getEXT_SLV_SENS_DATA_08()
	{
		return read8(EXT_SLV_SENS_DATA_08::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_09                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_09:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_09
	{
		static const uint16_t __address = 68;
		
		/* Bits EXT_SLV_SENS_DATA_09: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_09_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_09 */
	void setEXT_SLV_SENS_DATA_09(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_09::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_09 */
	uint8_t getEXT_SLV_SENS_DATA_09()
	{
		return read8(EXT_SLV_SENS_DATA_09::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_10                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_10:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_10
	{
		static const uint16_t __address = 69;
		
		/* Bits EXT_SLV_SENS_DATA_10: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_10_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_10 */
	void setEXT_SLV_SENS_DATA_10(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_10::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_10 */
	uint8_t getEXT_SLV_SENS_DATA_10()
	{
		return read8(EXT_SLV_SENS_DATA_10::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_11                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_11:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_11
	{
		static const uint16_t __address = 70;
		
		/* Bits EXT_SLV_SENS_DATA_11: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_11_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_11 */
	void setEXT_SLV_SENS_DATA_11(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_11::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_11 */
	uint8_t getEXT_SLV_SENS_DATA_11()
	{
		return read8(EXT_SLV_SENS_DATA_11::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_12                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_12:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_12
	{
		static const uint16_t __address = 71;
		
		/* Bits EXT_SLV_SENS_DATA_12: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_12_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_12 */
	void setEXT_SLV_SENS_DATA_12(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_12::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_12 */
	uint8_t getEXT_SLV_SENS_DATA_12()
	{
		return read8(EXT_SLV_SENS_DATA_12::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_13                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_13:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_13
	{
		static const uint16_t __address = 72;
		
		/* Bits EXT_SLV_SENS_DATA_13: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_13_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_13 */
	void setEXT_SLV_SENS_DATA_13(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_13::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_13 */
	uint8_t getEXT_SLV_SENS_DATA_13()
	{
		return read8(EXT_SLV_SENS_DATA_13::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_14                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_14:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_14
	{
		static const uint16_t __address = 73;
		
		/* Bits EXT_SLV_SENS_DATA_14: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_14_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_14 */
	void setEXT_SLV_SENS_DATA_14(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_14::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_14 */
	uint8_t getEXT_SLV_SENS_DATA_14()
	{
		return read8(EXT_SLV_SENS_DATA_14::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_15                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_15:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_15
	{
		static const uint16_t __address = 74;
		
		/* Bits EXT_SLV_SENS_DATA_15: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_15_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_15 */
	void setEXT_SLV_SENS_DATA_15(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_15::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_15 */
	uint8_t getEXT_SLV_SENS_DATA_15()
	{
		return read8(EXT_SLV_SENS_DATA_15::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_16                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_16:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_16
	{
		static const uint16_t __address = 75;
		
		/* Bits EXT_SLV_SENS_DATA_16: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_16_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_16 */
	void setEXT_SLV_SENS_DATA_16(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_16::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_16 */
	uint8_t getEXT_SLV_SENS_DATA_16()
	{
		return read8(EXT_SLV_SENS_DATA_16::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_17                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_17:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_17
	{
		static const uint16_t __address = 76;
		
		/* Bits EXT_SLV_SENS_DATA_17: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_17_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_17 */
	void setEXT_SLV_SENS_DATA_17(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_17::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_17 */
	uint8_t getEXT_SLV_SENS_DATA_17()
	{
		return read8(EXT_SLV_SENS_DATA_17::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_18                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_18:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_18
	{
		static const uint16_t __address = 77;
		
		/* Bits EXT_SLV_SENS_DATA_18: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_18_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_18 */
	void setEXT_SLV_SENS_DATA_18(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_18::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_18 */
	uint8_t getEXT_SLV_SENS_DATA_18()
	{
		return read8(EXT_SLV_SENS_DATA_18::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_19                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_19:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_19
	{
		static const uint16_t __address = 78;
		
		/* Bits EXT_SLV_SENS_DATA_19: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_19_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_19 */
	void setEXT_SLV_SENS_DATA_19(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_19::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_19 */
	uint8_t getEXT_SLV_SENS_DATA_19()
	{
		return read8(EXT_SLV_SENS_DATA_19::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_20                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_20:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_20
	{
		static const uint16_t __address = 79;
		
		/* Bits EXT_SLV_SENS_DATA_20: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_20_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_20 */
	void setEXT_SLV_SENS_DATA_20(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_20::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_20 */
	uint8_t getEXT_SLV_SENS_DATA_20()
	{
		return read8(EXT_SLV_SENS_DATA_20::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_21                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_21:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_21
	{
		static const uint16_t __address = 80;
		
		/* Bits EXT_SLV_SENS_DATA_21: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_21_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_21 */
	void setEXT_SLV_SENS_DATA_21(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_21::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_21 */
	uint8_t getEXT_SLV_SENS_DATA_21()
	{
		return read8(EXT_SLV_SENS_DATA_21::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_22                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_22:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_22
	{
		static const uint16_t __address = 81;
		
		/* Bits EXT_SLV_SENS_DATA_22: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_22_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_22 */
	void setEXT_SLV_SENS_DATA_22(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_22::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_22 */
	uint8_t getEXT_SLV_SENS_DATA_22()
	{
		return read8(EXT_SLV_SENS_DATA_22::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG EXT_SLV_SENS_DATA_23                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG EXT_SLV_SENS_DATA_23:
	 * type USR0, bank 0
	 */
	struct EXT_SLV_SENS_DATA_23
	{
		static const uint16_t __address = 82;
		
		/* Bits EXT_SLV_SENS_DATA_23: */
		/*
		 * Sensor data read from external I2C devices via the I2C master interface. The data
		 * stored is controlled by the I2C_SLV(0-4)_ADDR, I2C_SLV(0-4)_REG, and I2C_SLV(0-
		 * 4)_CTRL registers.
		 */
		struct EXT_SLV_SENS_DATA_23_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register EXT_SLV_SENS_DATA_23 */
	void setEXT_SLV_SENS_DATA_23(uint8_t value)
	{
		write(EXT_SLV_SENS_DATA_23::__address, value, 8);
	}
	
	/* Get register EXT_SLV_SENS_DATA_23 */
	uint8_t getEXT_SLV_SENS_DATA_23()
	{
		return read8(EXT_SLV_SENS_DATA_23::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG FIFO_EN_1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_EN_1:
	 * type USR0, bank 0
	 */
	struct FIFO_EN_1
	{
		static const uint16_t __address = 102;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits SLV_3_FIFO_EN: */
		/*
		 * 1 - Write EXT_SENS_DATA registers associated to SLV_3 (as determined by
		 * I2C_SLV2_CTRL, I2C_SLV1_CTRL, and I2C_SL20_CTRL)  to the FIFO at the sample rate;
		 * 0 - Function is disabled.
		 */
		struct SLV_3_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits SLV_2_FIFO_EN: */
		/*
		 * 1 - Write EXT_SENS_DATA registers associated to SLV_2 (as determined by
		 * I2C_SLV0_CTRL, I2C_SLV1_CTRL, and I2C_SL20_CTRL)  to the FIFO at the sample rate;
		 * 0 - Function is disabled.
		 */
		struct SLV_2_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits SLV_1_FIFO_EN: */
		/*
		 * 1 - Write EXT_SENS_DATA registers associated to SLV_1 (as determined by
		 * I2C_SLV0_CTRL and I2C_SLV1_CTRL)  to the FIFO at the sample rate;
		 * 0 - Function is disabled.
		 */
		struct SLV_1_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits SLV_0_FIFO_EN: */
		/*
		 * 1 - Write EXT_SENS_DATA registers associated to SLV_0 (as determined by
		 * I2C_SLV0_CTRL)  to the FIFO at the sample rate;
		 * 0 - Function is disabled.
		 */
		struct SLV_0_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register FIFO_EN_1 */
	void setFIFO_EN_1(uint8_t value)
	{
		write(FIFO_EN_1::__address, value, 8);
	}
	
	/* Get register FIFO_EN_1 */
	uint8_t getFIFO_EN_1()
	{
		return read8(FIFO_EN_1::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG FIFO_EN_2                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_EN_2:
	 * type USR0, bank 0
	 */
	struct FIFO_EN_2
	{
		static const uint16_t __address = 103;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits ACCEL_FIFO_EN: */
		/*
		 * 1 - Write ACCEL_XOUT_H, ACCEL_XOUT_L, ACCEL_YOUT_H, ACCEL_YOUT_L,
		 * ACCEL_ZOUT_H, and ACCEL_ZOUT_L to the FIFO at the sample rate;
		 * 0 - Function is disabled.
		 */
		struct ACCEL_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits GYRO_Z_FIFO_EN: */
		/*
		 * 1 - Write GYRO_ZOUT_H and GYRO_ZOUT_L to the FIFO at the sample rate.
		 * 0 - Function is disabled.
		 */
		struct GYRO_Z_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits GYRO_Y_FIFO_EN: */
		/*
		 * 1 - Write GYRO_YOUT_H and GYRO_YOUT_L to the FIFO at the sample rate.
		 * 0 - Function is disabled.
		 */
		struct GYRO_Y_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits GYRO_X_FIFO_EN: */
		/*
		 * 1 - Write GYRO_XOUT_H and GYRO_XOUT_L to the FIFO at the sample rate.
		 * 0 - Function is disabled.
		 */
		struct GYRO_X_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits TEMP_FIFO_EN: */
		/*
		 * 1 - Write TEMP_OUT_H and TEMP_OUT_L to the FIFO at the sample rate.
		 * 0 - Function is disabled.
		 */
		struct TEMP_FIFO_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register FIFO_EN_2 */
	void setFIFO_EN_2(uint8_t value)
	{
		write(FIFO_EN_2::__address, value, 8);
	}
	
	/* Get register FIFO_EN_2 */
	uint8_t getFIFO_EN_2()
	{
		return read8(FIFO_EN_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG FIFO_RST                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_RST:
	 * type USR0, bank 0
	 */
	struct FIFO_RST
	{
		static const uint16_t __address = 104;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_RESET: */
		/*
		 * S/W FIFO reset.  Assert and hold to set FIFO size to 0. Assert and de-assert to reset
		 * FIFO.
		 */
		struct FIFO_RESET
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_RST */
	void setFIFO_RST(uint8_t value)
	{
		write(FIFO_RST::__address, value, 8);
	}
	
	/* Get register FIFO_RST */
	uint8_t getFIFO_RST()
	{
		return read8(FIFO_RST::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG FIFO_MODE                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_MODE:
	 * type USR0, bank 0
	 */
	struct FIFO_MODE
	{
		static const uint16_t __address = 105;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_MODE: */
		/*
		 * 0 - Stream.
		 * 1 - Snapshot.
		 * When set to ‘1’, when the FIFO is full, additional writes will not be written to FIFO.
		 * When set to ‘0’, when the FIFO is full, additional writes will be written to the FIFO,
		 * replacing the oldest data.
		 */
		struct FIFO_MODE_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_MODE */
	void setFIFO_MODE(uint8_t value)
	{
		write(FIFO_MODE::__address, value, 8);
	}
	
	/* Get register FIFO_MODE */
	uint8_t getFIFO_MODE()
	{
		return read8(FIFO_MODE::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG FIFO_COUNTH                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_COUNTH:
	 * type USR0, bank 0
	 */
	struct FIFO_COUNTH
	{
		static const uint16_t __address = 112;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE r */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits FIFO_CNT: */
		/*
		 * High Bits, count indicates the number of written bytes in the FIFO.
		 * Reading this byte latches the data for both FIFO_COUNTH, and FIFO_COUNTL.
		 */
		struct FIFO_CNT
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_COUNTH */
	void setFIFO_COUNTH(uint8_t value)
	{
		write(FIFO_COUNTH::__address, value, 8);
	}
	
	/* Get register FIFO_COUNTH */
	uint8_t getFIFO_COUNTH()
	{
		return read8(FIFO_COUNTH::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG FIFO_COUNTL                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_COUNTL:
	 * type USR0, bank 0
	 */
	struct FIFO_COUNTL
	{
		static const uint16_t __address = 113;
		
		/* Bits FIFO_CNT: */
		/* Low bits, count indicates the number of written bytes in the FIFO.  */
		struct FIFO_CNT
		{
			/* MODE r */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register FIFO_COUNTL */
	void setFIFO_COUNTL(uint8_t value)
	{
		write(FIFO_COUNTL::__address, value, 8);
	}
	
	/* Get register FIFO_COUNTL */
	uint8_t getFIFO_COUNTL()
	{
		return read8(FIFO_COUNTL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG FIFO_R_W                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_R_W:
	 * type USR0, bank 0
	 */
	struct FIFO_R_W
	{
		static const uint16_t __address = 114;
		
		/* Bits FIFO_R_W: */
		/*
		 * Reading from or writing to this register actually reads/writes the FIFO. For example,
		 * to write a byte to the FIFO, write the desired byte value to FIFO_R_W[7:0]. To read a
		 * byte from the FIFO, perform a register read operation and access the result in
		 * FIFO_R_W[7:0].
		 */
		struct FIFO_R_W_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register FIFO_R_W */
	void setFIFO_R_W(uint8_t value)
	{
		write(FIFO_R_W::__address, value, 8);
	}
	
	/* Get register FIFO_R_W */
	uint8_t getFIFO_R_W()
	{
		return read8(FIFO_R_W::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                       REG DATA_RDY_STATUS                                        *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DATA_RDY_STATUS:
	 * type USR0, bank 0
	 */
	struct DATA_RDY_STATUS
	{
		static const uint16_t __address = 116;
		
		/* Bits WOF_STATUS: */
		/* Wake on FSYNC interrupt status. Cleared on read.  */
		struct WOF_STATUS
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rc */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b01110000; // [4,5,6]
		};
		/* Bits RAW_DATA_RDY: */
		/*
		 * Data from sensors is copied to FIFO or SRAM.
		 * Set when sequence controller kicks off on a sensor data load. Only bit 0 is relevant in
		 * a single FIFO configuration. Cleared on read.
		 */
		struct RAW_DATA_RDY
		{
			/* MODE rc */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register DATA_RDY_STATUS */
	void setDATA_RDY_STATUS(uint8_t value)
	{
		write(DATA_RDY_STATUS::__address, value, 8);
	}
	
	/* Get register DATA_RDY_STATUS */
	uint8_t getDATA_RDY_STATUS()
	{
		return read8(DATA_RDY_STATUS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG FIFO_CFG                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_CFG:
	 * type USR0, bank 0
	 */
	struct FIFO_CFG
	{
		static const uint16_t __address = 118;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits FIFO_CFG: */
		/* This bit should be set to 1 if interrupt status for each sensor is required.  */
		struct FIFO_CFG_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register FIFO_CFG */
	void setFIFO_CFG(uint8_t value)
	{
		write(FIFO_CFG::__address, value, 8);
	}
	
	/* Get register FIFO_CFG */
	uint8_t getFIFO_CFG()
	{
		return read8(FIFO_CFG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG REG_BANK_SEL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG REG_BANK_SEL:
	 * type ALL, bank 0
	 */
	struct REG_BANK_SEL
	{
		static const uint16_t __address = 127;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits USER_BANK: */
		/*
		 * Use the following values in this bit-field to select a USER BANK.
		 * 0: Select USER BANK 0.
		 * 1: Select USER BANK 1.
		 * 2: Select USER BANK 2.
		 * 3: Select USER BANK 3.
		 */
		struct USER_BANK
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits reserved_1: */
		struct reserved_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register REG_BANK_SEL */
	void setREG_BANK_SEL(uint8_t value)
	{
		write(REG_BANK_SEL::__address, value, 8);
	}
	
	/* Get register REG_BANK_SEL */
	uint8_t getREG_BANK_SEL()
	{
		return read8(REG_BANK_SEL::__address, 8);
	}
	
};
