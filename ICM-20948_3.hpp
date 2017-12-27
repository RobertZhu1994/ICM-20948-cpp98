/*
 * name:        ICM-20948
 * description: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications.
 * manuf:       TDK Invensense
 * version:     0.1
 * url:         https://www.invensense.com/wp-content/uploads/2016/06/DS-000189-ICM-20948-v1.3.pdf
 * date:        2017-10-18
 * author       https://chisl.io/
 * file:        ICM-20948_3.hpp
 */

#include <cinttypes>

/* Derive from class ICM_20948_3_Base and implement the read and write functions! */

/* ICM-20948: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications. */
class ICM_20948_3_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG I2C_MST_ODR_CONFIG                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_MST_ODR_CONFIG:
	 * type USR3, bank 3 
	 */
	struct I2C_MST_ODR_CONFIG
	{
		static const uint16_t __address = 0;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits I2C_MST_ODR_CONFIG: */
		/*
		 * ODR configuration for external sensor when gyroscope and accelerometer are
		 *           disabled.  ODR is computed as follows:
		 *           1.1 kHz/(2^((odr_config[3:0])) )
		 *           When gyroscope is enabled, all sensors (including I2C_MASTER) use the gyroscope
		 *           ODR. If gyroscope is disabled, then all sensors (including I2C_MASTER) use the
		 *           accelerometer ODR. 
		 */
		struct I2C_MST_ODR_CONFIG_
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_MST_ODR_CONFIG */
	void setI2C_MST_ODR_CONFIG(uint8_t value)
	{
		write(I2C_MST_ODR_CONFIG::__address, value, 8);
	}
	
	/* Get register I2C_MST_ODR_CONFIG */
	uint8_t getI2C_MST_ODR_CONFIG()
	{
		return read8(I2C_MST_ODR_CONFIG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_MST_CTRL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_MST_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_MST_CTRL
	{
		static const uint16_t __address = 1;
		
		/* Bits MULT_MST_EN: */
		/*
		 * Enables multi-master capability. When disabled, clocking to the I2C_MST_IF can be
		 *           disabled when not in use and the logic to detect lost arbitration is disabled. 
		 */
		struct MULT_MST_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b01100000; // [5,6]
		};
		/* Bits I2C_MST_P_NSR: */
		/*
		 * This bit controls the I2C Master’s transition from one slave read to the next slave
		 *           read.
		 *           0 - There is a restart between reads.
		 *           1 - There is a stop between reads. 
		 */
		struct I2C_MST_P_NSR
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_MST_CLK: */
		/* Sets I2C master clock frequency as shown in Table 23.  */
		struct I2C_MST_CLK
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_MST_CTRL */
	void setI2C_MST_CTRL(uint8_t value)
	{
		write(I2C_MST_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_MST_CTRL */
	uint8_t getI2C_MST_CTRL()
	{
		return read8(I2C_MST_CTRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG I2C_MST_DELAY_CTRL                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_MST_DELAY_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_MST_DELAY_CTRL
	{
		static const uint16_t __address = 2;
		
		/* Bits DELAY_ES_SHADOW: */
		/* Delays shadowing of external sensor data until all data is received.  */
		struct DELAY_ES_SHADOW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b01100000; // [5,6]
		};
		/* Bits I2C_SLV4_DELAY_EN: */
		/*
		 * When enabled, slave 4 will only be accessed 1/(1+I2C_SLC4_DLY) samples as
		 *           determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV4_DELAY_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV3_DELAY_EN: */
		/*
		 * When enabled, slave 3 will only be accessed 1/(1+I2C_SLC4_DLY) samples as
		 *           determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV3_DELAY_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits I2C_SLV2_DELAY_EN: */
		/*
		 * When enabled, slave 2 will only be accessed 1/(1+I2C_SLC4_DLY) samples as
		 *           determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV2_DELAY_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits I2C_SLV1_DELAY_EN: */
		/*
		 * When enabled, slave 1 will only be accessed 1/(1+I2C_SLC4_DLY) samples as
		 *           determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV1_DELAY_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits I2C_SLV0_DELAY_EN: */
		/*
		 * When enabled, slave 0 will only be accessed 1/(1+I2C_SLC4_DLY) samples as
		 *           determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV0_DELAY_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register I2C_MST_DELAY_CTRL */
	void setI2C_MST_DELAY_CTRL(uint8_t value)
	{
		write(I2C_MST_DELAY_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_MST_DELAY_CTRL */
	uint8_t getI2C_MST_DELAY_CTRL()
	{
		return read8(I2C_MST_DELAY_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV0_ADDR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV0_ADDR:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV0_ADDR
	{
		static const uint16_t __address = 3;
		
		/* Bits I2C_SLV0_RNW: */
		/*
		 * 1 - Transfer is a read.
		 *           0 - Transfer is a write. 
		 */
		struct I2C_SLV0_RNW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_ID_0: */
		/* Physical address of I2C slave 0.  */
		struct I2C_ID_0
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register I2C_SLV0_ADDR */
	void setI2C_SLV0_ADDR(uint8_t value)
	{
		write(I2C_SLV0_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SLV0_ADDR */
	uint8_t getI2C_SLV0_ADDR()
	{
		return read8(I2C_SLV0_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SLV0_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SLV0_REG:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV0_REG
	{
		static const uint16_t __address = 4;
		
		/* Bits I2C_SLV0_REG: */
		/* I2C slave 0 register address from where to begin data transfer.  */
		struct I2C_SLV0_REG_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV0_REG */
	void setI2C_SLV0_REG(uint8_t value)
	{
		write(I2C_SLV0_REG::__address, value, 8);
	}
	
	/* Get register I2C_SLV0_REG */
	uint8_t getI2C_SLV0_REG()
	{
		return read8(I2C_SLV0_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV0_CTRL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV0_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV0_CTRL
	{
		static const uint16_t __address = 5;
		
		/* Bits I2C_SLV0_EN: */
		/*
		 * 1 - Enable reading data from this slave at the sample rate and storing data at the first
		 *           available EXT_SENS_DATA register, which is always EXT_SENS_DATA_00 for I2C slave 0.
		 *           0 - Function is disabled for this slave. 
		 */
		struct I2C_SLV0_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV0_BYTE_SW: */
		/*
		 * 1 - Swap bytes when reading both the low and high byte of a word. Note there is
		 *           nothing to swap after reading the first byte if I2C_SLV0_REG[0] = 1, or if the last byte
		 *           read has a register address lsb = 0.
		 *           For example, if I2C_SLV0_REG = 0x1, and I2C_SLV0_LENG = 0x4:
		 *           1) The first byte read from address 0x1 will be stored at EXT_SENS_DATA_00,
		 *           2) the second and third bytes will be read and swapped, so the data read from address
		 *           0x2 will be stored at EXT_SENS_DATA_02, and the data read from address 0x3 will be
		 *           stored at EXT_SENS_DATA_01,
		 *           3) The last byte read from address 0x4 will be stored at EXT_SENS_DATA_03.
		 *           0 - No swapping occurs; bytes are written in order read. 
		 */
		struct I2C_SLV0_BYTE_SW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_SLV0_REG_DIS: */
		/*
		 * When set, the transaction does not write a register value, it will only read data, or write
		 *           data. 
		 */
		struct I2C_SLV0_REG_DIS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV0_GRP: */
		/*
		 * External sensor data typically comes in as groups of two bytes. This bit is used to
		 *           determine if the groups are from the slave’s register address 0 and 1, 2 and 3, etc.., or if
		 *           the groups are address 1 and 2, 3 and 4, etc.
		 *           0 indicates slave register addresses 0 and 1 are grouped together (odd numbered
		 *           register ends the group). 1 indicates slave register addresses 1 and 2 are grouped
		 *           together (even numbered register ends the group). This allows byte swapping of
		 *           registers that are grouped starting at any address. 
		 */
		struct I2C_SLV0_GRP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV0_LENG: */
		/* Number of bytes to be read from I2C slave 0.  */
		struct I2C_SLV0_LENG
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_SLV0_CTRL */
	void setI2C_SLV0_CTRL(uint8_t value)
	{
		write(I2C_SLV0_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_SLV0_CTRL */
	uint8_t getI2C_SLV0_CTRL()
	{
		return read8(I2C_SLV0_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV0_DO                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV0_DO:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV0_DO
	{
		static const uint16_t __address = 6;
		
		/* Bits I2C_SLV0_DO: */
		/* Data out when slave 0 is set to write.  */
		struct I2C_SLV0_DO_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV0_DO */
	void setI2C_SLV0_DO(uint8_t value)
	{
		write(I2C_SLV0_DO::__address, value, 8);
	}
	
	/* Get register I2C_SLV0_DO */
	uint8_t getI2C_SLV0_DO()
	{
		return read8(I2C_SLV0_DO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV1_ADDR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV1_ADDR:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV1_ADDR
	{
		static const uint16_t __address = 7;
		
		/* Bits I2C_SLV1_RNW: */
		/*
		 * 1 - Transfer is a read.
		 *           0 - Transfer is a write. 
		 */
		struct I2C_SLV1_RNW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_ID_1: */
		/* Physical address of I2C slave 1.  */
		struct I2C_ID_1
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register I2C_SLV1_ADDR */
	void setI2C_SLV1_ADDR(uint8_t value)
	{
		write(I2C_SLV1_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SLV1_ADDR */
	uint8_t getI2C_SLV1_ADDR()
	{
		return read8(I2C_SLV1_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SLV1_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SLV1_REG:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV1_REG
	{
		static const uint16_t __address = 8;
		
		/* Bits I2C_SLV1_REG: */
		/* I2C slave 1 register address from where to begin data transfer.  */
		struct I2C_SLV1_REG_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV1_REG */
	void setI2C_SLV1_REG(uint8_t value)
	{
		write(I2C_SLV1_REG::__address, value, 8);
	}
	
	/* Get register I2C_SLV1_REG */
	uint8_t getI2C_SLV1_REG()
	{
		return read8(I2C_SLV1_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV1_CTRL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV1_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV1_CTRL
	{
		static const uint16_t __address = 9;
		
		/* Bits I2C_SLV1_EN: */
		/*
		 * 1 - Enable reading data from this slave at the sample rate and storing data at the first
		 *           available EXT_SENS_DATA register as determined by I2C_SLV0_EN and
		 *           I2C_SLV0_LENG.
		 *           0 - Function is disabled for this slave. 
		 */
		struct I2C_SLV1_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV1_BYTE_SW: */
		/*
		 * 1 - Swap bytes when reading both the low and high byte of a word. Note there is
		 *           nothing to swap after reading the first byte if I2C_SLV1_REG[0] = 1, or if the last byte
		 *           read has a register address lsb = 0.
		 *           For example, if I2C_SLV0_EN = 0x1, and I2C_SLV0_LENG = 0x3 (to show swap has to
		 *           do with I2C slave address not EXT_SENS_DATA address), and if I2C_SLV1_REG = 0x1,
		 *           and I2C_SLV1_LENG = 0x4:
		 *           1) The first byte read from address 0x1 will be stored at EXT_SENS_DATA_03 (slave
		 *           0’s data will be in EXT_SENS_DATA_00, EXT_SENS_DATA_01, and
		 *           EXT_SENS_DATA_02),
		 *           2) the second and third bytes will be read and swapped, so the data read from
		 *           address 0x2 will be stored at EXT_SENS_DATA_04, and the data read from address
		 *           0x3 will be stored at EXT_SENS_DATA_05,
		 *           3) The last byte read from address 0x4 will be stored at EXT_SENS_DATA_06.
		 *           0 - No swapping occurs, bytes are written in order read. 
		 */
		struct I2C_SLV1_BYTE_SW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_SLV1_REG_DIS: */
		/*
		 * When set, the transaction does not write a register value, it will only read data, or
		 *           write data. 
		 */
		struct I2C_SLV1_REG_DIS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV1_GRP: */
		/*
		 * External sensor data typically comes in as groups of two bytes. This bit is used to
		 *           determine if the groups are from the slave’s register address 0 and 1, 2 and 3, etc..,
		 *           or if the groups are address 1 and 2, 3 and 4, etc.
		 *           0 indicates slave register addresses 0 and 1 are grouped together (odd numbered
		 *           register ends the group). 1 indicates slave register addresses 1 and 2 are grouped
		 *           together (even numbered register ends the group). This allows byte swapping of
		 *           registers that are grouped starting at any address. 
		 */
		struct I2C_SLV1_GRP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV1_LENG: */
		/* Number of bytes to be read from I2C slave 1.  */
		struct I2C_SLV1_LENG
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_SLV1_CTRL */
	void setI2C_SLV1_CTRL(uint8_t value)
	{
		write(I2C_SLV1_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_SLV1_CTRL */
	uint8_t getI2C_SLV1_CTRL()
	{
		return read8(I2C_SLV1_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV1_DO                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV1_DO:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV1_DO
	{
		static const uint16_t __address = 10;
		
		/* Bits I2C_SLV1_DO: */
		/* Data out when slave 1 is set to write.  */
		struct I2C_SLV1_DO_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV1_DO */
	void setI2C_SLV1_DO(uint8_t value)
	{
		write(I2C_SLV1_DO::__address, value, 8);
	}
	
	/* Get register I2C_SLV1_DO */
	uint8_t getI2C_SLV1_DO()
	{
		return read8(I2C_SLV1_DO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV2_ADDR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV2_ADDR:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV2_ADDR
	{
		static const uint16_t __address = 11;
		
		/* Bits I2C_SLV2_RNW: */
		/*
		 * 1 - Transfer is a read.
		 *           0 - Transfer is a write. 
		 */
		struct I2C_SLV2_RNW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_ID_2: */
		/* Physical address of I2C slave 2.  */
		struct I2C_ID_2
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register I2C_SLV2_ADDR */
	void setI2C_SLV2_ADDR(uint8_t value)
	{
		write(I2C_SLV2_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SLV2_ADDR */
	uint8_t getI2C_SLV2_ADDR()
	{
		return read8(I2C_SLV2_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SLV2_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SLV2_REG:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV2_REG
	{
		static const uint16_t __address = 12;
		
		/* Bits I2C_SLV2_REG: */
		/* I2C slave 2 register address from where to begin data transfer.  */
		struct I2C_SLV2_REG_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV2_REG */
	void setI2C_SLV2_REG(uint8_t value)
	{
		write(I2C_SLV2_REG::__address, value, 8);
	}
	
	/* Get register I2C_SLV2_REG */
	uint8_t getI2C_SLV2_REG()
	{
		return read8(I2C_SLV2_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV2_CTRL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV2_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV2_CTRL
	{
		static const uint16_t __address = 13;
		
		/* Bits I2C_SLV2_EN: */
		/*
		 * 1 - Enable reading data from this slave at the sample rate and storing data at the first
		 *           available EXT_SENS_DATA register as determined by I2C_SLV0_EN, I2C_SLV0_LENG,
		 *           I2C_SLV1_EN and I2C_SLV1_LENG.
		 *           0 - Function is disabled for this slave. 
		 */
		struct I2C_SLV2_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV2_BYTE_SW: */
		/*
		 * 1 - Swap bytes when reading both the low and high byte of a word. Note there is
		 *           nothing to swap after reading the first byte if I2C_SLV2_REG[0] = 1, or if the last byte
		 *           read has a register address lsb = 0.
		 *           See I2C_SLV1_CTRL for an example.
		 *           0 - No swapping occurs, bytes are written in order read. 
		 */
		struct I2C_SLV2_BYTE_SW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_SLV2_REG_DIS: */
		/*
		 * When set, the transaction does not write a register value, it will only read data, or
		 *           write data. 
		 */
		struct I2C_SLV2_REG_DIS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV2_GRP: */
		/*
		 * External sensor data typically comes in as groups of two bytes. This bit is used to
		 *           determine if the groups are from the slave’s register address 0 and 1, 2 and 3, etc..,
		 *           or if the groups are address 1 and 2, 3 and 4, etc.
		 *           0 indicates slave register addresses 0 and 1 are grouped together (odd numbered
		 *           register ends the group). 1 indicates slave register addresses 1 and 2 are grouped
		 *           together (even numbered register ends the group). This allows byte swapping of
		 *           registers that are grouped starting at any address. 
		 */
		struct I2C_SLV2_GRP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV2_LENG: */
		/* Number of bytes to be read from I2C slave 2.  */
		struct I2C_SLV2_LENG
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_SLV2_CTRL */
	void setI2C_SLV2_CTRL(uint8_t value)
	{
		write(I2C_SLV2_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_SLV2_CTRL */
	uint8_t getI2C_SLV2_CTRL()
	{
		return read8(I2C_SLV2_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV2_DO                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV2_DO:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV2_DO
	{
		static const uint16_t __address = 14;
		
		/* Bits I2C_SLV2_DO: */
		/* Data out when slave 2 is set to write.  */
		struct I2C_SLV2_DO_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV2_DO */
	void setI2C_SLV2_DO(uint8_t value)
	{
		write(I2C_SLV2_DO::__address, value, 8);
	}
	
	/* Get register I2C_SLV2_DO */
	uint8_t getI2C_SLV2_DO()
	{
		return read8(I2C_SLV2_DO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV3_ADDR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV3_ADDR:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV3_ADDR
	{
		static const uint16_t __address = 15;
		
		/* Bits I2C_SLV3_RNW: */
		/*
		 * 1 - Transfer is a read.
		 *           0 - Transfer is a write. 
		 */
		struct I2C_SLV3_RNW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_ID_3: */
		/* Physical address of I2C slave 3.  */
		struct I2C_ID_3
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register I2C_SLV3_ADDR */
	void setI2C_SLV3_ADDR(uint8_t value)
	{
		write(I2C_SLV3_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SLV3_ADDR */
	uint8_t getI2C_SLV3_ADDR()
	{
		return read8(I2C_SLV3_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SLV3_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SLV3_REG:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV3_REG
	{
		static const uint16_t __address = 16;
		
		/* Bits I2C_SLV3_REG: */
		/* I2C slave 3 register address from where to begin data transfer.  */
		struct I2C_SLV3_REG_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV3_REG */
	void setI2C_SLV3_REG(uint8_t value)
	{
		write(I2C_SLV3_REG::__address, value, 8);
	}
	
	/* Get register I2C_SLV3_REG */
	uint8_t getI2C_SLV3_REG()
	{
		return read8(I2C_SLV3_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV3_CTRL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV3_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV3_CTRL
	{
		static const uint16_t __address = 17;
		
		/* Bits I2C_SLV3_EN: */
		/*
		 * 1 - Enable reading data from this slave at the sample rate and storing data at the first
		 *           available EXT_SENS_DATA register as determined by I2C_SLV0_EN, I2C_SLV0_LENG,
		 *           I2C_SLV1_EN, I2C_SLV1_LENG, I2C_SLV2_EN and I2C_SLV2_LENG.
		 *           0 - Function is disabled for this slave. 
		 */
		struct I2C_SLV3_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV3_BYTE_SW: */
		/*
		 * 1 - Swap bytes when reading both the low and high byte of a word.  Note there is
		 *           nothing to swap after reading the first byte if I2C_SLV3_REG[0] = 1, or if the last byte
		 *           read has a register address lsb = 0.
		 *           See I2C_SLV1_CTRL for an example.
		 *           0 - No swapping occurs, bytes are written in order read. 
		 */
		struct I2C_SLV3_BYTE_SW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_SLV3_REG_DIS: */
		/*
		 * When set, the transaction does not write a register value, it will only read data, or
		 *           write data. 
		 */
		struct I2C_SLV3_REG_DIS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV3_GRP: */
		/*
		 * External sensor data typically comes in as groups of two bytes. This bit is used to
		 *           determine if the groups are from the slave’s register address 0 and 1, 2 and 3, etc..,
		 *           or if the groups are address 1 and 2, 3 and 4, etc.
		 *           0 indicates slave register addresses 0 and 1 are grouped together (odd numbered
		 *           register ends the group). 1 indicates slave register addresses 1 and 2 are grouped
		 *           together (even numbered register ends the group). This allows byte swapping of
		 *           registers that are grouped starting at any address. 
		 */
		struct I2C_SLV3_GRP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits I2C_SLV3_LENG: */
		/* Number of bytes to be read from I2C slave 3.  */
		struct I2C_SLV3_LENG
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register I2C_SLV3_CTRL */
	void setI2C_SLV3_CTRL(uint8_t value)
	{
		write(I2C_SLV3_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_SLV3_CTRL */
	uint8_t getI2C_SLV3_CTRL()
	{
		return read8(I2C_SLV3_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV3_DO                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV3_DO:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV3_DO
	{
		static const uint16_t __address = 18;
		
		/* Bits I2C_SLV3_DO: */
		/* Data out when slave 3 is set to write.  */
		struct I2C_SLV3_DO_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV3_DO */
	void setI2C_SLV3_DO(uint8_t value)
	{
		write(I2C_SLV3_DO::__address, value, 8);
	}
	
	/* Get register I2C_SLV3_DO */
	uint8_t getI2C_SLV3_DO()
	{
		return read8(I2C_SLV3_DO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV4_ADDR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV4_ADDR:
	 * type USR3, bank 3 
	 * The I2C Slave 4 interface can be used to perform only single byte read and write transactions. 
	 */
	struct I2C_SLV4_ADDR
	{
		static const uint16_t __address = 19;
		
		/* Bits I2C_SLV4_RNW: */
		/*
		 * 1 - Transfer is a read.
		 *           0 - Transfer is a write. 
		 */
		struct I2C_SLV4_RNW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_ID_4: */
		/* Physical address of I2C slave 4.  */
		struct I2C_ID_4
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register I2C_SLV4_ADDR */
	void setI2C_SLV4_ADDR(uint8_t value)
	{
		write(I2C_SLV4_ADDR::__address, value, 8);
	}
	
	/* Get register I2C_SLV4_ADDR */
	uint8_t getI2C_SLV4_ADDR()
	{
		return read8(I2C_SLV4_ADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG I2C_SLV4_REG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG I2C_SLV4_REG:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV4_REG
	{
		static const uint16_t __address = 20;
		
		/* Bits I2C_SLV4_REG: */
		/* I2C slave 4 register address from where to begin data transfer.  */
		struct I2C_SLV4_REG_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV4_REG */
	void setI2C_SLV4_REG(uint8_t value)
	{
		write(I2C_SLV4_REG::__address, value, 8);
	}
	
	/* Get register I2C_SLV4_REG */
	uint8_t getI2C_SLV4_REG()
	{
		return read8(I2C_SLV4_REG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG I2C_SLV4_CTRL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV4_CTRL:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV4_CTRL
	{
		static const uint16_t __address = 21;
		
		/* Bits I2C_SLV4_EN: */
		/*
		 * 1 - Enable data transfer with this slave at the sample rate. If read command, store
		 *           data in I2C_SLV4_DI register, if write command, write data stored in I2C_SLV4_DO
		 *           register. Bit is cleared when a single transfer is complete. Be sure to write
		 *           I2C_SLV4_DO first.
		 *           0 - Function is disabled for this slave. 
		 */
		struct I2C_SLV4_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits I2C_SLV4_INT_EN: */
		/*
		 * 1 - Enables the completion of the I2C slave 4 data transfer to cause an interrupt.
		 *           0 - Completion of the I2C slave 4 data transfer will not cause an interrupt. 
		 */
		struct I2C_SLV4_INT_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits I2C_SLV4_REG_DIS: */
		/*
		 * When set, the transaction does not write a register value, it will only read data, or
		 *           write data. 
		 */
		struct I2C_SLV4_REG_DIS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits I2C_SLV4_DLY: */
		/*
		 * When enabled via the I2C_MST_DELAY_CTRL, those slaves will only be enabled
		 *           every1/(1+I2C_SLV4_DLY) samples as determined by I2C_MST_ODR_CONFIG. 
		 */
		struct I2C_SLV4_DLY
		{
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register I2C_SLV4_CTRL */
	void setI2C_SLV4_CTRL(uint8_t value)
	{
		write(I2C_SLV4_CTRL::__address, value, 8);
	}
	
	/* Get register I2C_SLV4_CTRL */
	uint8_t getI2C_SLV4_CTRL()
	{
		return read8(I2C_SLV4_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV4_DO                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV4_DO:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV4_DO
	{
		static const uint16_t __address = 22;
		
		/* Bits I2C_SLV4_DO: */
		/* Data out when slave 4 is set to write.  */
		struct I2C_SLV4_DO_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV4_DO */
	void setI2C_SLV4_DO(uint8_t value)
	{
		write(I2C_SLV4_DO::__address, value, 8);
	}
	
	/* Get register I2C_SLV4_DO */
	uint8_t getI2C_SLV4_DO()
	{
		return read8(I2C_SLV4_DO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG I2C_SLV4_DI                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG I2C_SLV4_DI:
	 * type USR3, bank 3 
	 */
	struct I2C_SLV4_DI
	{
		static const uint16_t __address = 23;
		
		/* Bits I2C_SLV4_DI: */
		/* Data read from I2C Slave 4.  */
		struct I2C_SLV4_DI_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register I2C_SLV4_DI */
	void setI2C_SLV4_DI(uint8_t value)
	{
		write(I2C_SLV4_DI::__address, value, 8);
	}
	
	/* Get register I2C_SLV4_DI */
	uint8_t getI2C_SLV4_DI()
	{
		return read8(I2C_SLV4_DI::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG REG_BANK_SEL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG REG_BANK_SEL:
	 * type , bank 3 
	 */
	struct REG_BANK_SEL
	{
		static const uint16_t __address = 127;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits USER_BANK: */
		/*
		 * Use the following values in this bit-field to select a USER BANK.
		 *           0: Select USER BANK 0.
		 *           1: Select USER BANK 1.
		 *           2: Select USER BANK 2.
		 *           3: Select USER BANK 3. 
		 */
		struct USER_BANK
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits reserved_1: */
		struct reserved_1
		{
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
