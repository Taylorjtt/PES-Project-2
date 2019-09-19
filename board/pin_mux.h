/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0RXSRC_UART_RX 0x00u /*!<@brief UART0 receive data source select: UART0_RX pin */
#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART0 transmit data source select: UART0_TX pin */

/*! @name PORTA2 (number 28), J1[4]/D1/UART0_TX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL UART0          /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL TX                 /*!<@brief UART0 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PORT PORTA                /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN 2U                    /*!<@brief PORTA pin index: 2 */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME UART0_TX         /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL "J1[4]/D1/UART0_TX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME "DEBUG_UART_TX"      /*!<@brief Identifier name */
                                                               /* @} */

/*! @name PORTA1 (number 27), J1[2]/D0/UART0_RX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL UART0          /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL RX                 /*!<@brief UART0 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PORT PORTA                /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN 1U                    /*!<@brief PORTA pin index: 1 */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME UART0_RX         /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL "J1[2]/D0/UART0_RX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME "DEBUG_UART_RX"      /*!<@brief Identifier name */
                                                               /* @} */

/*! @name PORTD1 (number 74), J2[12]/D3[3]/D13/LEDRGB_BLUE
  @{ */
#define BOARD_INITPINS_LED_BLUE_PERIPHERAL GPIOD                     /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_LED_BLUE_SIGNAL GPIO                          /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_LED_BLUE_GPIO GPIOD                           /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN 1U                          /*!<@brief PORTD pin index: 1 */
#define BOARD_INITPINS_LED_BLUE_PORT PORTD                           /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LED_BLUE_PIN 1U                               /*!<@brief PORTD pin index: 1 */
#define BOARD_INITPINS_LED_BLUE_CHANNEL 1                            /*!<@brief GPIOD GPIO channel: 1 */
#define BOARD_INITPINS_LED_BLUE_PIN_NAME PTD1                        /*!<@brief Pin name */
#define BOARD_INITPINS_LED_BLUE_LABEL "J2[12]/D3[3]/D13/LEDRGB_BLUE" /*!<@brief Label */
#define BOARD_INITPINS_LED_BLUE_NAME "LED_BLUE"                      /*!<@brief Identifier name */
#define BOARD_INITPINS_LED_BLUE_DIRECTION kPIN_MUX_DirectionOutput   /*!<@brief Direction */
                                                                     /* @} */

/*! @name PORTB19 (number 54), D3[4]/LEDRGB_GREEN
  @{ */
#define BOARD_INITPINS_LED_GREEN_PERIPHERAL GPIOB                   /*!<@brief Device name: GPIOB */
#define BOARD_INITPINS_LED_GREEN_SIGNAL GPIO                        /*!<@brief GPIOB signal: GPIO */
#define BOARD_INITPINS_LED_GREEN_GPIO GPIOB                         /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED_GREEN_GPIO_PIN 19U                       /*!<@brief PORTB pin index: 19 */
#define BOARD_INITPINS_LED_GREEN_PORT PORTB                         /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED_GREEN_PIN 19U                            /*!<@brief PORTB pin index: 19 */
#define BOARD_INITPINS_LED_GREEN_CHANNEL 19                         /*!<@brief GPIOB GPIO channel: 19 */
#define BOARD_INITPINS_LED_GREEN_PIN_NAME PTB19                     /*!<@brief Pin name */
#define BOARD_INITPINS_LED_GREEN_LABEL "D3[4]/LEDRGB_GREEN"         /*!<@brief Label */
#define BOARD_INITPINS_LED_GREEN_NAME "LED_GREEN"                   /*!<@brief Identifier name */
#define BOARD_INITPINS_LED_GREEN_DIRECTION kPIN_MUX_DirectionOutput /*!<@brief Direction */
                                                                    /* @} */

/*! @name PORTB18 (number 53), D3[1]/LEDRGB_RED
  @{ */
#define BOARD_INITPINS_LED_RED_PERIPHERAL GPIOB                   /*!<@brief Device name: GPIOB */
#define BOARD_INITPINS_LED_RED_SIGNAL GPIO                        /*!<@brief GPIOB signal: GPIO */
#define BOARD_INITPINS_LED_RED_GPIO GPIOB                         /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LED_RED_GPIO_PIN 18U                       /*!<@brief PORTB pin index: 18 */
#define BOARD_INITPINS_LED_RED_PORT PORTB                         /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED_RED_PIN 18U                            /*!<@brief PORTB pin index: 18 */
#define BOARD_INITPINS_LED_RED_CHANNEL 18                         /*!<@brief GPIOB GPIO channel: 18 */
#define BOARD_INITPINS_LED_RED_PIN_NAME PTB18                     /*!<@brief Pin name */
#define BOARD_INITPINS_LED_RED_LABEL "D3[1]/LEDRGB_RED"           /*!<@brief Label */
#define BOARD_INITPINS_LED_RED_NAME "LED_RED"                     /*!<@brief Identifier name */
#define BOARD_INITPINS_LED_RED_DIRECTION kPIN_MUX_DirectionOutput /*!<@brief Direction */
                                                                  /* @} */

/*! @name PORTB16 (number 51), TSI0_CH9
  @{ */
#define BOARD_INITPINS_TSI_ELECTRODE_1_PERIPHERAL TSI0        /*!<@brief Device name: TSI0 */
#define BOARD_INITPINS_TSI_ELECTRODE_1_SIGNAL CH              /*!<@brief TSI0 signal: CH */
#define BOARD_INITPINS_TSI_ELECTRODE_1_PORT PORTB             /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_TSI_ELECTRODE_1_PIN 16U                /*!<@brief PORTB pin index: 16 */
#define BOARD_INITPINS_TSI_ELECTRODE_1_CHANNEL 9              /*!<@brief TSI0 channel: 9 */
#define BOARD_INITPINS_TSI_ELECTRODE_1_PIN_NAME TSI0_CH9      /*!<@brief Pin name */
#define BOARD_INITPINS_TSI_ELECTRODE_1_LABEL "TSI0_CH9"       /*!<@brief Label */
#define BOARD_INITPINS_TSI_ELECTRODE_1_NAME "TSI_ELECTRODE_1" /*!<@brief Identifier name */
                                                              /* @} */

/*! @name PORTB17 (number 52), TSI0_CH10
  @{ */
#define BOARD_INITPINS_TSI_ELECTRODE_2_PERIPHERAL TSI0        /*!<@brief Device name: TSI0 */
#define BOARD_INITPINS_TSI_ELECTRODE_2_SIGNAL CH              /*!<@brief TSI0 signal: CH */
#define BOARD_INITPINS_TSI_ELECTRODE_2_PORT PORTB             /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_TSI_ELECTRODE_2_PIN 17U                /*!<@brief PORTB pin index: 17 */
#define BOARD_INITPINS_TSI_ELECTRODE_2_CHANNEL 10             /*!<@brief TSI0 channel: 10 */
#define BOARD_INITPINS_TSI_ELECTRODE_2_PIN_NAME TSI0_CH10     /*!<@brief Pin name */
#define BOARD_INITPINS_TSI_ELECTRODE_2_LABEL "TSI0_CH10"      /*!<@brief Label */
#define BOARD_INITPINS_TSI_ELECTRODE_2_NAME "TSI_ELECTRODE_2" /*!<@brief Identifier name */
                                                              /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
