#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sched.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include "BBBiolib.h"
#include "BBBiolib_McASP.h"

/* Device register memory map */
#define MCASP0_MMAP_ADDR	0x48038000
#define MCASP1_MMAP_ADDR	0x4803C000
#define MCASP_MMAP_LEN	0x1000


#define MCASP_ARG_MODULE_COUNT	2
#define MCASP_ARG_CHANNEL_COUNT	2

/* Device register offset */

/* Power Idle register */
#define MCASP_SYSCONFIG	0x04

/* Global register */
#define MCASP_REV	0x0 // default value 0x44300A02 to check the registers access 
#define MCASP_PFUNC 0x10
#define MCASP_PDIR 0x14
#define MCASP_PDOUT 0x18
#define MCASP_PDSET 0x1C
#define MCASP_PDIN 0x1C
#define MCASP_PDCLR 0x20
#define MCASP_DITCTL 0x50 // DIT Mode
#define MCASP_DLBCTL 0x4C // Digital Loopback
#define MCASP_AMUTE 0x48 // Audio mute
#define MCASP_GBLCTL 0x44 // Global

/* Receiver register */
#define MCASP_RGBLCTL 0x60 // Global Receiver
#define MCASP_RMASK 0x64 // Bit mask receive
#define MCASP_RFMT 0x68 // Format Receive Bit stream
#define MCASP_AFSRCTL 0x6C //Receive Frame Sync
#define MCASP_ACLKRCTL 0x70 // Receive clock low speed
#define MCASP_AHCLKRCTL 0x74 // Receive clock high speed
#define MCASP_RTDM 0x78 // Receive TDM Slot
#define MCASP_RINTCTL 0x7C //Receive Interrupt
#define MCASP_RCLKCHK 0x88 //Receive Clock Check 

#define MCASP_RBUF0_RBUF5 0x280 // Receive buffer

/* Serializer Register */
#define MCASP_SRCTL0_SRCTL5 0x180 // Serializer

/* Transmitter register */
#define MCASP_XGBLCTL 0xA0 // Global Transmitter
#define MCASP_XMASL 0xA4 // Bit mask transmit
#define MCASP_ACLKXCTL 0xB0 // Transmit clock low speed
#define MCASP_XBUF0_XBUF5 0x200 // Transmit buffer

/* McSPI module struct */
struct BBBIO_McASP_struct
{
	int CM_PER_enable ;
	//struct BBBIO_McSPI_CH_struct CH[MCSPI_ARG_CHANNEL_COUNT];
};


extern int memh;
extern volatile unsigned int *cm_per_addr ;

const unsigned int McASP_AddressOffset[]={MCASP0_MMAP_ADDR, MCASP1_MMAP_ADDR};

struct BBBIO_McASP_struct McASP_Module[MCASP_ARG_MODULE_COUNT] ={0} ;

volatile unsigned int *mcasp_ptr[MCASP_ARG_CHANNEL_COUNT] ={NULL};
/* ----------------------------------------------------------------------------------------------- */
inline void write_reg_mcasp(volatile void *reg_base ,unsigned int offset ,unsigned int data)
{
	*((volatile unsigned int* )(reg_base+offset)) = data;
}
/* ----------------------------------------------------------------------------------------------- */
inline unsigned int read_reg_mcasp(volatile void *reg_base ,unsigned int offset)
{
	return *((volatile unsigned int* )(reg_base+offset));
}
int test_register_mcasp(void)
{ 
	 printf("%X\r\n", read_reg_mcasp(mcasp_ptr[0], 0x4));
	 return 1;
}
int BBBIO_McASP_Init(int module)
{
	int i ;
	if (memh == 0) {

		printf("BBBIO_PWM_Init: memory not mapped?\n");

		return 0;
    }

	
		mcasp_ptr[module] = mmap(NULL, MCASP_MMAP_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, memh, McASP_AddressOffset[module]);
		if(mcasp_ptr[module] == MAP_FAILED) {

			printf("BBBIO_McSPI_Init: McASP %d mmap failure!\n",i);

	                return 0;
		}
	
    return 1;
}
int BBBIO_McASP_Setting_Dummy(void)
{
	// Test with McASP 0 in receiver only as a Slave
	
	//copy pin mux
	//0x190 0x20	 mcasp0_aclkx.mcasp0_aclkx, INPUT | MODE0 
	//0x194 0x20	 mcasp0_fsx.mcasp0_fsx, INPUT | MODE0 
	//0x19c 0x22	 mcasp0_ahclkr.mcasp0_axr2, INPUT | MODE2 
	//0x1ac 0x22	/* mcasp0_ahclkx.mcasp0_axr3, INPUT | MODE2 
	
	
	// Configure Clock
	// External Clock
	// No internally
	// Clock polarity -> 0 - rising edge and no bi separated
	// External Frame Sync
	// Frame sync polarity -> 3
	// Frame sync width -> 16 word of 16 bits
	// Receive is sync
	
	// Configure Data format
	// Integer format
	// Format i2s (left-justified)
	// 0 bit time slot delay
	// MSB first
	// No padding
	// No slot
	// No rotate
	// No mask
	// 44100 Khz, 16bits (for start)
	
	// Configure Data Transfer
	// No DMA -> CPU
	// TDM no burst
	// BUS DAT
	
	//Reset Mcasp GBLCTL 0
	 
	 
	
}

int BBBIO_McASP_Setting(unsigned int McSPI_ID ,int i
	
	
						)
{
	
	// Configure Pins
	
	// Configure Clock
	
	// Configure Data format
	
	// Configure Data Transfer
	
	// Final Check
	
	return 1;
}						

int BBBIO_McASP_Transmit(unsigned int McSPI_ID , int i)
{
	return 0;
}

int BBBIO_McASP_Receive(unsigned int McSPI_ID , int j)
{
	return 1;
}
