
 #include "stm32f4xx.h"


#define NOMBRE_BOUCLES 100

/* Private variables ---------------------------------------------------------*/

// determiner l'adresse de register RCC_AHB1ENR pour activer l'horlge de GPIO D
volatile unsigned short int *RCC_AHB1ENR = (unsigned short int *) 0x40023830; 

// determiner l'adresse de register GPIOD_MODER
volatile unsigned  int *GPIOD_MODER = (unsigned int *) 0x40020C00;  

// determiner l'adresse de register GPIOD_ODR
volatile unsigned  int *GPIOD_ODR = (unsigned int *) 0x40020C14;  

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */

unsigned  int counter = 0x00;  

  // Determiner la valeur de masque pour activer l'horloge de GPIO D
  *RCC_AHB1ENR |= (1<<3);
  //VALUE_AHB1ENR |= (1<<3) ;
  
  // Determiner la valeur de masque pour pr�parer la configureation la pin PD12 
  *GPIOD_MODER |=  (1<<24);
  
    // Determiner la valeur de masque pour pr�parer la configureation la pin PD13
  *GPIOD_MODER |=  (1<<26);
  
  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
   /* mettre le pin 12 a 1 */
    *GPIOD_ODR |= (1<<12);

    /* mettre le pin 13 a 1 */
    *GPIOD_ODR |= (1<<13);
    
    Delay(0x3FFFFF) ;

    /* mettre le pin 12 a 0 */
    *GPIOD_ODR &= ~(1<<12);

    /* mettre le pin 13 a 0 */    
    *GPIOD_ODR &= ~(1<<13);
    
    Delay(0x3FFFFF) ;
           
  }  
  while (1)
  {}
}

/**
  * @brief  Delay Function.
  * @param  nCount:specifies the Delay time length.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

