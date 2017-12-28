/*
 * name:        ICM-20948
 * description: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications.
 * manuf:       TDK Invensense
 * version:     0.1
 * url:         https://www.invensense.com/wp-content/uploads/2016/06/DS-000189-ICM-20948-v1.3.pdf
 * date:        2017-10-18
 * author       https://chisl.io/
 * file:        ICM-20948_1.hpp
 */

#include <cinttypes>

/* Derive from class ICM_20948_1_Base and implement the read and write functions! */

/* ICM-20948: Low power 9-axis MotionTracking device that is ideally suited for Smartphones, Tablets, Wearable Sensors, and IoT applications. */
class ICM_20948_1_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG SELF_TEST_X_GYRO                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_X_GYRO:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_X_GYRO
	{
		static const uint16_t __address = 2;
		
		/* Bits XG_ST_DATA: */
		/*
		 * The value in this register indicates the self-test output generated during
		 * manufacturing tests. This value is to be used to check against subsequent self-test
		 * outputs performed by the end user.
		 */
		struct XG_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_X_GYRO */
	void setSELF_TEST_X_GYRO(uint8_t value)
	{
		write(SELF_TEST_X_GYRO::__address, value, 8);
	}
	
	/* Get register SELF_TEST_X_GYRO */
	uint8_t getSELF_TEST_X_GYRO()
	{
		return read8(SELF_TEST_X_GYRO::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG SELF_TEST_Y_GYRO                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_Y_GYRO:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_Y_GYRO
	{
		static const uint16_t __address = 3;
		
		/* Bits YG_ST_DATA: */
		/*
		 * The value in this register indicates the self-test output generated during
		 * manufacturing tests. This value is to be used to check against subsequent self-test
		 * outputs performed by the end user.
		 */
		struct YG_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_Y_GYRO */
	void setSELF_TEST_Y_GYRO(uint8_t value)
	{
		write(SELF_TEST_Y_GYRO::__address, value, 8);
	}
	
	/* Get register SELF_TEST_Y_GYRO */
	uint8_t getSELF_TEST_Y_GYRO()
	{
		return read8(SELF_TEST_Y_GYRO::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG SELF_TEST_Z_GYRO                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_Z_GYRO:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_Z_GYRO
	{
		static const uint16_t __address = 4;
		
		/* Bits ZG_ST_DATA: */
		/*
		 * The value in this register indicates the self-test output generated during
		 * manufacturing tests. This value is to be used to check against subsequent self-test
		 * outputs performed by the end user.
		 */
		struct ZG_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_Z_GYRO */
	void setSELF_TEST_Z_GYRO(uint8_t value)
	{
		write(SELF_TEST_Z_GYRO::__address, value, 8);
	}
	
	/* Get register SELF_TEST_Z_GYRO */
	uint8_t getSELF_TEST_Z_GYRO()
	{
		return read8(SELF_TEST_Z_GYRO::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                      REG SELF_TEST_X_ACCEL                                       *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_X_ACCEL:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_X_ACCEL
	{
		static const uint16_t __address = 14;
		
		/* Bits XA_ST_DATA: */
		/* Contains self-test data for the X Accelerometer.  */
		struct XA_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_X_ACCEL */
	void setSELF_TEST_X_ACCEL(uint8_t value)
	{
		write(SELF_TEST_X_ACCEL::__address, value, 8);
	}
	
	/* Get register SELF_TEST_X_ACCEL */
	uint8_t getSELF_TEST_X_ACCEL()
	{
		return read8(SELF_TEST_X_ACCEL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                      REG SELF_TEST_Y_ACCEL                                       *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_Y_ACCEL:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_Y_ACCEL
	{
		static const uint16_t __address = 15;
		
		/* Bits YA_ST_DATA: */
		/* Contains self-test data for the Y Accelerometer.  */
		struct YA_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_Y_ACCEL */
	void setSELF_TEST_Y_ACCEL(uint8_t value)
	{
		write(SELF_TEST_Y_ACCEL::__address, value, 8);
	}
	
	/* Get register SELF_TEST_Y_ACCEL */
	uint8_t getSELF_TEST_Y_ACCEL()
	{
		return read8(SELF_TEST_Y_ACCEL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                      REG SELF_TEST_Z_ACCEL                                       *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SELF_TEST_Z_ACCEL:
	 * type USR1, bank 1
	 */
	struct SELF_TEST_Z_ACCEL
	{
		static const uint16_t __address = 16;
		
		/* Bits ZA_ST_DATA: */
		/* Contains self-test data for the Z Accelerometer.  */
		struct ZA_ST_DATA
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SELF_TEST_Z_ACCEL */
	void setSELF_TEST_Z_ACCEL(uint8_t value)
	{
		write(SELF_TEST_Z_ACCEL::__address, value, 8);
	}
	
	/* Get register SELF_TEST_Z_ACCEL */
	uint8_t getSELF_TEST_Z_ACCEL()
	{
		return read8(SELF_TEST_Z_ACCEL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG XA_OFFS_H                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG XA_OFFS_H:
	 * type USR1, bank 1
	 */
	struct XA_OFFS_H
	{
		static const uint16_t __address = 20;
		
		/* Bits XA_OFFS: */
		/* Upper bits of the X accelerometer offset cancellation.  */
		struct XA_OFFS
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register XA_OFFS_H */
	void setXA_OFFS_H(uint8_t value)
	{
		write(XA_OFFS_H::__address, value, 8);
	}
	
	/* Get register XA_OFFS_H */
	uint8_t getXA_OFFS_H()
	{
		return read8(XA_OFFS_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG XA_OFFS_L                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG XA_OFFS_L:
	 * type USR1, bank 1
	 */
	struct XA_OFFS_L
	{
		static const uint16_t __address = 21;
		
		/* Bits XA_OFFS: */
		/* Lower bits of the X accelerometer offset cancellation.  */
		struct XA_OFFS
		{
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register XA_OFFS_L */
	void setXA_OFFS_L(uint8_t value)
	{
		write(XA_OFFS_L::__address, value, 8);
	}
	
	/* Get register XA_OFFS_L */
	uint8_t getXA_OFFS_L()
	{
		return read8(XA_OFFS_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG YA_OFFS_H                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG YA_OFFS_H:
	 * type USR1, bank 1
	 */
	struct YA_OFFS_H
	{
		static const uint16_t __address = 23;
		
		/* Bits YA_OFFS: */
		/* Upper bits of the Y accelerometer offset cancellation.  */
		struct YA_OFFS
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register YA_OFFS_H */
	void setYA_OFFS_H(uint8_t value)
	{
		write(YA_OFFS_H::__address, value, 8);
	}
	
	/* Get register YA_OFFS_H */
	uint8_t getYA_OFFS_H()
	{
		return read8(YA_OFFS_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG YA_OFFS_L                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG YA_OFFS_L:
	 * type USR1, bank 1
	 */
	struct YA_OFFS_L
	{
		static const uint16_t __address = 24;
		
		/* Bits YA_OFFS: */
		/* Lower bits of the Y accelerometer offset cancellation.  */
		struct YA_OFFS
		{
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register YA_OFFS_L */
	void setYA_OFFS_L(uint8_t value)
	{
		write(YA_OFFS_L::__address, value, 8);
	}
	
	/* Get register YA_OFFS_L */
	uint8_t getYA_OFFS_L()
	{
		return read8(YA_OFFS_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG ZA_OFFS_H                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG ZA_OFFS_H:
	 * type USR1, bank 1
	 */
	struct ZA_OFFS_H
	{
		static const uint16_t __address = 26;
		
		/* Bits ZA_OFFS: */
		/* Upper bits of the Z accelerometer offset cancellation.  */
		struct ZA_OFFS
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register ZA_OFFS_H */
	void setZA_OFFS_H(uint8_t value)
	{
		write(ZA_OFFS_H::__address, value, 8);
	}
	
	/* Get register ZA_OFFS_H */
	uint8_t getZA_OFFS_H()
	{
		return read8(ZA_OFFS_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG ZA_OFFS_L                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG ZA_OFFS_L:
	 * type USR1, bank 1
	 */
	struct ZA_OFFS_L
	{
		static const uint16_t __address = 27;
		
		/* Bits ZA_OFFS: */
		/* Lower bits of the Z accelerometer offset cancellation.  */
		struct ZA_OFFS
		{
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ZA_OFFS_L */
	void setZA_OFFS_L(uint8_t value)
	{
		write(ZA_OFFS_L::__address, value, 8);
	}
	
	/* Get register ZA_OFFS_L */
	uint8_t getZA_OFFS_L()
	{
		return read8(ZA_OFFS_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                   REG TIMEBASE_CORRECTION_PLL                                    *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TIMEBASE_CORRECTION_PLL:
	 * type USR1, bank 1
	 */
	struct TIMEBASE_CORRECTION_PLL
	{
		static const uint16_t __address = 40;
		
		/* Bits TBC_PLL: */
		/* System PLL clock period error (signed, [-10%, +10%]).  */
		struct TBC_PLL
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TIMEBASE_CORRECTION_PLL */
	void setTIMEBASE_CORRECTION_PLL(uint8_t value)
	{
		write(TIMEBASE_CORRECTION_PLL::__address, value, 8);
	}
	
	/* Get register TIMEBASE_CORRECTION_PLL */
	uint8_t getTIMEBASE_CORRECTION_PLL()
	{
		return read8(TIMEBASE_CORRECTION_PLL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG REG_BANK_SEL                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG REG_BANK_SEL:
	 * type , bank 1
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
