#ifndef BBBIO_MCASP_H
#define BBBIO_MCASP_H

#define BBBIO_McASP_ASP1	0
#define BBBIO_McASP_ASP2	1


/* Rerence AM335x Techinal Reference Manual .
 *	Session 24.3.1.1 , 24.3.1.2.1 , 24.3.1.2.2
 */
#define BBBIO_McSPI_Master	0x0
#define BBBIO_McSPI_Slave	0x1

#define BBBIO_McSPI_TxRx	0x0
#define BBBIO_McSPI_Rx_Only	0x1
#define BBBIO_McSPI_Tx_Only	0x2

//-------------------------------------------------------------------------
int BBBIO_McSPI_work(unsigned int McSPI_ID);

int BBBIO_McSPI_Init() ;

void BBBIO_McSPI_Tx(unsigned int McSPI_ID ,unsigned int channel ,unsigned int data) ;

unsigned int BBBIO_McSPI_Rx(unsigned int McSPI_ID ,unsigned int channel ) ;
int test_register_mcasp(unsigned int toto);
#define BBBIO_McSPI_Enable(a) BBBIO_McSPI_CLK_set(a,1,0)
#define BBBIO_McSPI_Disable(a) BBBIO_McSPI_CLK_set(a,0,0)
int BBBIO_McSPI_CLK_set(unsigned int McSPI_ID ,int enable , int idle) ;

int BBBIO_McSPI_Setting(unsigned int McSPI_ID ,
                        unsigned int channel,
                        unsigned int MS,		/* MS		 , maset or slave */
                        unsigned int TRM ,		/* TRM		 , Tx only / Rx only , TxRx */
                        unsigned int CLK_div ,		/* Clock Divider , default clock : 48M Hz */
                        unsigned int CLKmode ,		/* POL/PHA ,     , clock polarity */
                        unsigned int EPOL ,
                        unsigned int DataDir ,		/* IS/DPE1/DPE0	 ,data0 Outpu    t data1 Input ,or data0 Input data1 Output */
                        unsigned int WL);		// WL		 ,word length */

void BBBIO_McSPI_Reset(unsigned int McSPI_ID);

//-------------------------------------------------------------------------



#endif
