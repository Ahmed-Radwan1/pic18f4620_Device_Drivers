#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU/BUTTON/ecu_button.c ECU/CHAR_LCD/ecu_char_lcd.c ECU/DC_MOTOR/ecu_dc_motor.c ECU/KEY_PAD/ecu_kaypad.c ECU/LED/ecu_led.c ECU/RELAY/ecu_relay.c ECU/SEVEN_SEGMENT/ecu_seven_segment.c ECU/ecu_layer_init.c MCAL/ADC/mcal_adc.c MCAL/CCP1/mcal_ccp1.c MCAL/EEPROM/mcal_eeprom.c MCAL/GPIO/hal_gpio.c MCAL/INTERRUPT/mcal_internal_interrupt.c MCAL/INTERRUPT/mcal_external_interrupt.c MCAL/INTERRUPT/mcal_interrupt_manager.c MCAL/TIMER0/mcal_timer0.c MCAL/TIMER1/mcal_timer1.c MCAL/TIMER2/mcal_timer2.c MCAL/TIMER3/mcal_timer3.c MCAL/USART/mcal_usart.c MCAL/device_config.c application.c MCAL/I2C/mcal_i2c.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 ${OBJECTDIR}/ECU/LED/ecu_led.p1 ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d ${OBJECTDIR}/MCAL/device_config.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 ${OBJECTDIR}/ECU/LED/ecu_led.p1 ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1

# Source Files
SOURCEFILES=ECU/BUTTON/ecu_button.c ECU/CHAR_LCD/ecu_char_lcd.c ECU/DC_MOTOR/ecu_dc_motor.c ECU/KEY_PAD/ecu_kaypad.c ECU/LED/ecu_led.c ECU/RELAY/ecu_relay.c ECU/SEVEN_SEGMENT/ecu_seven_segment.c ECU/ecu_layer_init.c MCAL/ADC/mcal_adc.c MCAL/CCP1/mcal_ccp1.c MCAL/EEPROM/mcal_eeprom.c MCAL/GPIO/hal_gpio.c MCAL/INTERRUPT/mcal_internal_interrupt.c MCAL/INTERRUPT/mcal_external_interrupt.c MCAL/INTERRUPT/mcal_interrupt_manager.c MCAL/TIMER0/mcal_timer0.c MCAL/TIMER1/mcal_timer1.c MCAL/TIMER2/mcal_timer2.c MCAL/TIMER3/mcal_timer3.c MCAL/USART/mcal_usart.c MCAL/device_config.c application.c MCAL/I2C/mcal_i2c.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/BUTTON/ecu_button.p1: ECU/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ECU/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/ecu_button.d ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1: ECU/CHAR_LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 ECU/CHAR_LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1: ECU/DC_MOTOR/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ECU/DC_MOTOR/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1: ECU/KEY_PAD/ecu_kaypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEY_PAD" 
	@${RM} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 ECU/KEY_PAD/ecu_kaypad.c 
	@-${MV} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.d ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/ecu_led.p1: ECU/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/ecu_led.p1 ECU/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/ecu_led.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/ecu_relay.p1: ECU/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ECU/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/ecu_relay.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1: ECU/SEVEN_SEGMENT/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 ECU/SEVEN_SEGMENT/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/mcal_adc.p1: MCAL/ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 MCAL/ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/mcal_adc.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1: MCAL/CCP1/mcal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 MCAL/CCP1/mcal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.d ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1: MCAL/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 MCAL/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1: MCAL/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 MCAL/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1: MCAL/INTERRUPT/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 MCAL/INTERRUPT/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1: MCAL/INTERRUPT/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 MCAL/INTERRUPT/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1: MCAL/TIMER0/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 MCAL/TIMER0/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.d ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1: MCAL/TIMER1/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 MCAL/TIMER1/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.d ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1: MCAL/TIMER2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 MCAL/TIMER2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1: MCAL/TIMER3/mcal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 MCAL/TIMER3/mcal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.d ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/USART/mcal_usart.p1: MCAL/USART/mcal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/USART" 
	@${RM} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 MCAL/USART/mcal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL/USART/mcal_usart.d ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1: MCAL/I2C/mcal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 MCAL/I2C/mcal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/BUTTON/ecu_button.p1: ECU/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ECU/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/ecu_button.d ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1: ECU/CHAR_LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1 ECU/CHAR_LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/CHAR_LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1: ECU/DC_MOTOR/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ECU/DC_MOTOR/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1: ECU/KEY_PAD/ecu_kaypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEY_PAD" 
	@${RM} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1 ECU/KEY_PAD/ecu_kaypad.c 
	@-${MV} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.d ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEY_PAD/ecu_kaypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/ecu_led.p1: ECU/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/ecu_led.p1 ECU/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/ecu_led.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/ecu_relay.p1: ECU/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ECU/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/ecu_relay.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1: ECU/SEVEN_SEGMENT/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1 ECU/SEVEN_SEGMENT/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/mcal_adc.p1: MCAL/ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 MCAL/ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/mcal_adc.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1: MCAL/CCP1/mcal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1 MCAL/CCP1/mcal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.d ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP1/mcal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1: MCAL/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1 MCAL/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1: MCAL/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1 MCAL/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1: MCAL/INTERRUPT/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1 MCAL/INTERRUPT/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1: MCAL/INTERRUPT/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1 MCAL/INTERRUPT/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1: MCAL/TIMER0/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1 MCAL/TIMER0/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.d ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER0/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1: MCAL/TIMER1/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1 MCAL/TIMER1/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.d ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1: MCAL/TIMER2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 MCAL/TIMER2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1: MCAL/TIMER3/mcal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1 MCAL/TIMER3/mcal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.d ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER3/mcal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/USART/mcal_usart.p1: MCAL/USART/mcal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/USART" 
	@${RM} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/USART/mcal_usart.p1 MCAL/USART/mcal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL/USART/mcal_usart.d ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/USART/mcal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1: MCAL/I2C/mcal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 MCAL/I2C/mcal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACING_PROJECTS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
