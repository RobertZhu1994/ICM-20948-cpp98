/*
 * name:        ICM-20948
 * description: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications.
 * manuf:       TDK Invensense
 * version:     0.1
 * url:         https://www.invensense.com/wp-content/uploads/2016/06/DS-000189-ICM-20948-v1.3.pdf
 * date:        2017-10-18
 * author       https://chisl.io/
 * file:        ICM-20948_2.hpp
 */

#include <cinttypes>

/* Derive from class ICM_20948_2_Base and implement the read and write functions! */

/* ICM-20948: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications. */
class ICM_20948_2_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                       REG GYRO_SMPLRT_DIV                                        *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_SMPLRT_DIV:
	 * type USR2, bank 2
	 */
	struct GYRO_SMPLRT_DIV
	{
		static const uint16_t __address = 0;
		
		/* Bits GYRO_SMPLRT_DIV: */
		/*
		 * Gyro sample rate divider. Divides the internal sample rate to generate the sample
		 * rate that controls sensor data output rate, FIFO sample rate, and DMP sequence rate.
		 * NOTE: This register is only effective when FCHOICE = 1’b1 (FCHOICE_B register bit is 1’b0), and
		 * (0 < DLPF_CFG < 7).
		 * ODR is computed as follows:
		 * 1.1 kHz/(1+GYRO_SMPLRT_DIV[7:0])
		 */
		struct GYRO_SMPLRT_DIV_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register GYRO_SMPLRT_DIV */
	void setGYRO_SMPLRT_DIV(uint8_t value)
	{
		write(GYRO_SMPLRT_DIV::__address, value, 8);
	}
	
	/* Get register GYRO_SMPLRT_DIV */
	uint8_t getGYRO_SMPLRT_DIV()
	{
		return read8(GYRO_SMPLRT_DIV::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG GYRO_CONFIG_1                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_CONFIG_1:
	 * type USR2, bank 2
	 * The gyroscope DLPF is configured by GYRO_DLPFCFG, when GYRO_FCHOICE = 1. The gyroscope data is filtered
	 * according to the value of GYRO_DLPFCFG and GYRO_FCHOICE as shown in Table 16.
	 */
	struct GYRO_CONFIG_1
	{
		static const uint16_t __address = 1;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits GYRO_DLPFCFG: */
		/* Gyro low pass filter configuration as shown in Table 16.  */
		struct GYRO_DLPFCFG
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00111000; // [3,4,5]
		};
		/* Bits GYRO_FS_SEL: */
		/*
		 * Gyro Full Scale Select:
		 * 00 = ±250 dps
		 * 01= ±500 dps
		 * 10 = ±1000 dps
		 * 11 = ±2000 dps
		 */
		struct GYRO_FS_SEL
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
		};
		/* Bits GYRO_FCHOICE: */
		/*
		 * 0 - Bypass gyro DLPF.
		 * 1 - Enable gyro DLPF.
		 */
		struct GYRO_FCHOICE
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register GYRO_CONFIG_1 */
	void setGYRO_CONFIG_1(uint8_t value)
	{
		write(GYRO_CONFIG_1::__address, value, 8);
	}
	
	/* Get register GYRO_CONFIG_1 */
	uint8_t getGYRO_CONFIG_1()
	{
		return read8(GYRO_CONFIG_1::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG GYRO_CONFIG_2                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG GYRO_CONFIG_2:
	 * type USR2, bank 2
	 */
	struct GYRO_CONFIG_2
	{
		static const uint16_t __address = 2;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits XGYRO_CTEN: */
		/* X Gyro self-test enable.  */
		struct XGYRO_CTEN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits YGYRO_CTEN: */
		/* Y Gyro self-test enable.  */
		struct YGYRO_CTEN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits ZGYRO_CTEN: */
		/* Z Gyro self-test enable.  */
		struct ZGYRO_CTEN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits GYRO_AVGCFG: */
		/*
		 * Averaging filter configuration settings for low-power mode.
		 * 0: 1x averaging.
		 * 1: 2x averaging.
		 * 2: 4x averaging.
		 * 3: 8x averaging.
		 * 4: 16x averaging.
		 * 5: 32x averaging.
		 * 6: 64x averaging.
		 * 7: 128x averaging.
		 */
		struct GYRO_AVGCFG
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register GYRO_CONFIG_2 */
	void setGYRO_CONFIG_2(uint8_t value)
	{
		write(GYRO_CONFIG_2::__address, value, 8);
	}
	
	/* Get register GYRO_CONFIG_2 */
	uint8_t getGYRO_CONFIG_2()
	{
		return read8(GYRO_CONFIG_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG XG_OFFS_USRH                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG XG_OFFS_USRH:
	 * type USR2, bank 2
	 */
	struct XG_OFFS_USRH
	{
		static const uint16_t __address = 3;
		
		/* Bits X_OFFS_USER: */
		/* Upper byte of X gyro offset cancellation.  */
		struct X_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register XG_OFFS_USRH */
	void setXG_OFFS_USRH(uint8_t value)
	{
		write(XG_OFFS_USRH::__address, value, 8);
	}
	
	/* Get register XG_OFFS_USRH */
	uint8_t getXG_OFFS_USRH()
	{
		return read8(XG_OFFS_USRH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG XG_OFFS_USRL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG XG_OFFS_USRL:
	 * type USR2, bank 2
	 */
	struct XG_OFFS_USRL
	{
		static const uint16_t __address = 4;
		
		/* Bits X_OFFS_USER: */
		/* Lower byte of X gyro offset cancellation.  */
		struct X_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register XG_OFFS_USRL */
	void setXG_OFFS_USRL(uint8_t value)
	{
		write(XG_OFFS_USRL::__address, value, 8);
	}
	
	/* Get register XG_OFFS_USRL */
	uint8_t getXG_OFFS_USRL()
	{
		return read8(XG_OFFS_USRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG YG_OFFS_USRH                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG YG_OFFS_USRH:
	 * type USR2, bank 2
	 */
	struct YG_OFFS_USRH
	{
		static const uint16_t __address = 5;
		
		/* Bits Y_OFFS_USER: */
		/* Upper byte of Y gyro offset cancellation.  */
		struct Y_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register YG_OFFS_USRH */
	void setYG_OFFS_USRH(uint8_t value)
	{
		write(YG_OFFS_USRH::__address, value, 8);
	}
	
	/* Get register YG_OFFS_USRH */
	uint8_t getYG_OFFS_USRH()
	{
		return read8(YG_OFFS_USRH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG YG_OFFS_USRL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG YG_OFFS_USRL:
	 * type USR2, bank 2
	 */
	struct YG_OFFS_USRL
	{
		static const uint16_t __address = 6;
		
		/* Bits Y_OFFS_USER: */
		/* Lower byte of Y gyro offset cancellation.  */
		struct Y_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register YG_OFFS_USRL */
	void setYG_OFFS_USRL(uint8_t value)
	{
		write(YG_OFFS_USRL::__address, value, 8);
	}
	
	/* Get register YG_OFFS_USRL */
	uint8_t getYG_OFFS_USRL()
	{
		return read8(YG_OFFS_USRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ZG_OFFS_USRH                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ZG_OFFS_USRH:
	 * type USR2, bank 2
	 */
	struct ZG_OFFS_USRH
	{
		static const uint16_t __address = 7;
		
		/* Bits Z_OFFS_USER: */
		/* Upper byte of Z gyro offset cancellation.  */
		struct Z_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ZG_OFFS_USRH */
	void setZG_OFFS_USRH(uint8_t value)
	{
		write(ZG_OFFS_USRH::__address, value, 8);
	}
	
	/* Get register ZG_OFFS_USRH */
	uint8_t getZG_OFFS_USRH()
	{
		return read8(ZG_OFFS_USRH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ZG_OFFS_USRL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ZG_OFFS_USRL:
	 * type USR2, bank 2
	 */
	struct ZG_OFFS_USRL
	{
		static const uint16_t __address = 8;
		
		/* Bits Z_OFFS_USER: */
		/* Lower byte of Z gyro offset cancellation.  */
		struct Z_OFFS_USER
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ZG_OFFS_USRL */
	void setZG_OFFS_USRL(uint8_t value)
	{
		write(ZG_OFFS_USRL::__address, value, 8);
	}
	
	/* Get register ZG_OFFS_USRL */
	uint8_t getZG_OFFS_USRL()
	{
		return read8(ZG_OFFS_USRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ODR_ALIGN_EN                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ODR_ALIGN_EN:
	 * type USR2, bank 2, OTP No
	 */
	struct ODR_ALIGN_EN
	{
		static const uint16_t __address = 9;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits ODR_ALIGN_EN: */
		/*
		 * 0: Disables ODR start-time alignment.
		 * 1: Enables ODR start-time alignment when any of the following registers is written
		 * (with the same value or with different values):  GYRO_SMPLRT_DIV,
		 * ACCEL_SMPLRT_DIV_1, ACCEL_SMPLRT_DIV_2, I2C_MST_ODR_CONFIG.
		 */
		struct ODR_ALIGN_EN_
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ODR_ALIGN_EN */
	void setODR_ALIGN_EN(uint8_t value)
	{
		write(ODR_ALIGN_EN::__address, value, 8);
	}
	
	/* Get register ODR_ALIGN_EN */
	uint8_t getODR_ALIGN_EN()
	{
		return read8(ODR_ALIGN_EN::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG ACCEL_SMPLRT_DIV_1                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_SMPLRT_DIV_1:
	 * type USR2, bank 2
	 */
	struct ACCEL_SMPLRT_DIV_1
	{
		static const uint16_t __address = 16;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits ACCEL_SMPLRT_DIV: */
		/* MSB for ACCEL sample rate div.  */
		struct ACCEL_SMPLRT_DIV
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register ACCEL_SMPLRT_DIV_1 */
	void setACCEL_SMPLRT_DIV_1(uint8_t value)
	{
		write(ACCEL_SMPLRT_DIV_1::__address, value, 8);
	}
	
	/* Get register ACCEL_SMPLRT_DIV_1 */
	uint8_t getACCEL_SMPLRT_DIV_1()
	{
		return read8(ACCEL_SMPLRT_DIV_1::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG ACCEL_SMPLRT_DIV_2                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_SMPLRT_DIV_2:
	 * type USR2, bank 2
	 */
	struct ACCEL_SMPLRT_DIV_2
	{
		static const uint16_t __address = 17;
		
		/* Bits ACCEL_SMPLRT_DIV: */
		/*
		 * LSB for ACCEL sample rate div.
		 * ODR is computed as follows:
		 * 1.125 kHz/(1+ACCEL_SMPLRT_DIV[11:0])
		 */
		struct ACCEL_SMPLRT_DIV
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_SMPLRT_DIV_2 */
	void setACCEL_SMPLRT_DIV_2(uint8_t value)
	{
		write(ACCEL_SMPLRT_DIV_2::__address, value, 8);
	}
	
	/* Get register ACCEL_SMPLRT_DIV_2 */
	uint8_t getACCEL_SMPLRT_DIV_2()
	{
		return read8(ACCEL_SMPLRT_DIV_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG ACCEL_INTEL_CTRL                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_INTEL_CTRL:
	 * type USR2, bank 2
	 */
	struct ACCEL_INTEL_CTRL
	{
		static const uint16_t __address = 18;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits ACCEL_INTEL_EN: */
		/* Enable the WOM logic.  */
		struct ACCEL_INTEL_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits ACCEL_INTEL_MODE_INT: */
		/*
		 * Selects WOM algorithm.
		 * 1 = Compare the current sample with the previous sample.
		 * 0 = Initial sample is stored, all future samples are compared to the initial sample.
		 */
		struct ACCEL_INTEL_MODE_INT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ACCEL_INTEL_CTRL */
	void setACCEL_INTEL_CTRL(uint8_t value)
	{
		write(ACCEL_INTEL_CTRL::__address, value, 8);
	}
	
	/* Get register ACCEL_INTEL_CTRL */
	uint8_t getACCEL_INTEL_CTRL()
	{
		return read8(ACCEL_INTEL_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG ACCEL_WOM_THR                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG ACCEL_WOM_THR:
	 * type USR2, bank 2
	 */
	struct ACCEL_WOM_THR
	{
		static const uint16_t __address = 19;
		
		/* Bits WOM_THRESHOLD: */
		/*
		 * This register holds the threshold value for the Wake on Motion Interrupt for ACCEL
		 * x/y/z axes. LSB = 4 mg. Range is 0 mg to 1020 mg.
		 */
		struct WOM_THRESHOLD
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ACCEL_WOM_THR */
	void setACCEL_WOM_THR(uint8_t value)
	{
		write(ACCEL_WOM_THR::__address, value, 8);
	}
	
	/* Get register ACCEL_WOM_THR */
	uint8_t getACCEL_WOM_THR()
	{
		return read8(ACCEL_WOM_THR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG ACCEL_CONFIG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_CONFIG:
	 * type USR2, bank 2
	 * The data rate out of the DLPF filter block can be further reduced by a factor of
	 * 1.125 kHz/(1+ACCEL_SMPLRT_DIV[11:0]) where ACCEL_SMPLRT_DIV is a 12-bit integer.
	 */
	struct ACCEL_CONFIG
	{
		static const uint16_t __address = 20;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits ACCEL_DLPFCFG: */
		/* Accelerometer low pass filter configuration as shown in Table 18.  */
		struct ACCEL_DLPFCFG
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00111000; // [3,4,5]
		};
		/* Bits ACCEL_FS_SEL: */
		/*
		 * Accelerometer Full Scale Select:
		 * 00: ±2g
		 * 01: ±4g
		 * 10: ±8g
		 * 11: ±16g
		 */
		struct ACCEL_FS_SEL
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
		};
		/* Bits ACCEL_FCHOICE: */
		/*
		 * 0: Bypass accel DLPF.
		 * 1: Enable accel DLPF.
		 */
		struct ACCEL_FCHOICE
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ACCEL_CONFIG */
	void setACCEL_CONFIG(uint8_t value)
	{
		write(ACCEL_CONFIG::__address, value, 8);
	}
	
	/* Get register ACCEL_CONFIG */
	uint8_t getACCEL_CONFIG()
	{
		return read8(ACCEL_CONFIG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG ACCEL_CONFIG_2                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACCEL_CONFIG_2:
	 * type USR2, bank 2
	 */
	struct ACCEL_CONFIG_2
	{
		static const uint16_t __address = 21;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits AX_ST_EN_REG: */
		/* X Accel self-test enable.  */
		struct AX_ST_EN_REG
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits AY_ST_EN_REG: */
		/* Y Accel self-test enable.  */
		struct AY_ST_EN_REG
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits AZ_ST_EN_REG: */
		/* Z Accel self-test enable.  */
		struct AZ_ST_EN_REG
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits DEC3_CFG: */
		/*
		 * Controls the number of samples averaged in the accelerometer decimator:
		 * 0: Average 1 or 4 samples depending on ACCEL_FCHOICE (see Table 19).
		 * 1: Average 8 samples.
		 * 2: Average 16 samples.
		 * 3: Average 32 samples.
		 */
		struct DEC3_CFG
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
		};
	};
	
	/* Set register ACCEL_CONFIG_2 */
	void setACCEL_CONFIG_2(uint8_t value)
	{
		write(ACCEL_CONFIG_2::__address, value, 8);
	}
	
	/* Get register ACCEL_CONFIG_2 */
	uint8_t getACCEL_CONFIG_2()
	{
		return read8(ACCEL_CONFIG_2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG FSYNC_CONFIG                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FSYNC_CONFIG:
	 * type USR2, bank 2
	 */
	struct FSYNC_CONFIG
	{
		static const uint16_t __address = 82;
		
		/* Bits DELAY_TIME_EN: */
		/*
		 * 0: Disables delay time measurement between FSYNC event and the first ODR event
		 * (after FSYNC event).
		 * 1: Enables delay time measurement between FSYNC event and the first ODR event
		 * (after FSYNC event).
		 */
		struct DELAY_TIME_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits WOF_DEGLITCH_EN: */
		/* Enable digital deglitching of FSYNC input for Wake on FSYNC.  */
		struct WOF_DEGLITCH_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits WOF_EDGE_INT: */
		/*
		 * 0: FSYNC is a level interrupt for Wake on FSYNC.
		 * 1: FSYNC is an edge interrupt for Wake on FSYNC.
		 * ACTL_FSYNC is used to set the polarity of the interrupt.
		 */
		struct WOF_EDGE_INT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits EXT_SYNC_SET: */
		/*
		 * Enables the FSYNC pin data to be sampled.
		 * EXT_SYNC_SET FSYNC bit location.
		 * 0: Function disabled.
		 * 1: TEMP_OUT_L[0].
		 * 2: GYRO_XOUT_L[0].
		 * 3: GYRO_YOUT_L[0].
		 * 4: GYRO_ZOUT_L[0].
		 * 5: ACCEL_XOUT_L[0].
		 * 6: ACCEL_YOUT_L[0].
		 * 7: ACCEL_ZOUT_L[0].
		 */
		struct EXT_SYNC_SET
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register FSYNC_CONFIG */
	void setFSYNC_CONFIG(uint8_t value)
	{
		write(FSYNC_CONFIG::__address, value, 8);
	}
	
	/* Get register FSYNC_CONFIG */
	uint8_t getFSYNC_CONFIG()
	{
		return read8(FSYNC_CONFIG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG TEMP_CONFIG                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TEMP_CONFIG:
	 * type USR2, bank 2
	 */
	struct TEMP_CONFIG
	{
		static const uint16_t __address = 83;
		
		/* Bits TEMP_DLPFCFG: */
		/*
		 * Low pass filter configuration for temperature sensor as shown in the table below:
		 * TEMP_DLPCFG<2:0> TEMP SENSOR
		 * NBW (HZ) RATE (KHZ)
		 * 0 7932 9
		 * 1 217.9 1.125
		 * 2 123.5 1.125
		 * 3 65.9 1.125
		 * 4 34.1 1.125
		 * 5 17.3 1.125
		 * 6 8.8 Rate (kHz)
		 * 7 7932 9
		 */
		struct TEMP_DLPFCFG
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register TEMP_CONFIG */
	void setTEMP_CONFIG(uint8_t value)
	{
		write(TEMP_CONFIG::__address, value, 8);
	}
	
	/* Get register TEMP_CONFIG */
	uint8_t getTEMP_CONFIG()
	{
		return read8(TEMP_CONFIG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG MOD_CTRL_USR                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG MOD_CTRL_USR:
	 * type USR2, bank 2
	 */
	struct MOD_CTRL_USR
	{
		static const uint16_t __address = 84;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000001; // 7'b1
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits REG_LP_DMP_EN: */
		/* Enable turning on DMP in Low Power Accelerometer mode.  */
		struct REG_LP_DMP_EN
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register MOD_CTRL_USR */
	void setMOD_CTRL_USR(uint8_t value)
	{
		write(MOD_CTRL_USR::__address, value, 8);
	}
	
	/* Get register MOD_CTRL_USR */
	uint8_t getMOD_CTRL_USR()
	{
		return read8(MOD_CTRL_USR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG REG_BANK_SEL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG REG_BANK_SEL:
	 * type USR2, bank 2
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
		 * 0: Select USER BANK 0.
		 * 1: Select USER BANK 1.
		 * 2: Select USER BANK 2.
		 * 3: Select USER BANK 3.
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
