// react

// Includes

#include <M5StickC.h>

#include "env.h"

extern "C" {
#include "react.h"
}

// Exported functions and variables

blc_bool buttonPressed = false;

blc_nat32 blc_react_makeRandomNat32 (const blc_nat32 blc_fromIncl, const blc_nat32 blc_toExcl)
{
  return random(blc_fromIncl, blc_toExcl);                    
}

void blc_react_dimScreen (const blc_nat8 blc_percentage)
{
  M5.Axp.ScreenBreath(blc_percentage * 12 / 100);
}

void blc_react_displayCountDownScreen (const blc_nat8 blc_i)
{
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(35, 75, 4);
  M5.Lcd.printf("%d", (int)blc_i); 
}

void blc_react_displaySplashScreen (void)
{
  M5.Lcd.fillScreen(BLUE);
}

void blc_react_displayStartScreen ()
{
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  M5.Lcd.println("REACT\n");
  M5.Lcd.println("1x click:");      
  M5.Lcd.println("\t Start\n");      
  M5.Lcd.println("2x click:");      
  M5.Lcd.println("\t Help");      
}

void blc_react_displayHelpScreen (void)
{
  M5.Lcd.fillScreen(YELLOW);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  M5.Lcd.println("HELP\n");
  M5.Lcd.println("Click as fast as possible when blue screen appears.");        
}

void blc_react_displayPlayStartScreen (void)
{
  M5.Lcd.fillScreen(BLACK);
}

void blc_react_displayPlaySignalScreen (void)
{
  M5.Lcd.fillScreen(BLUE);
}

void blc_react_displayResultIsValidScreen (const struct blc_react_Score *const blc_score)
{
  M5.Lcd.fillScreen(GREEN);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 0, 2);
  M5.Lcd.println("OK\n\n");
  M5.Lcd.println("Time:");
  M5.Lcd.printf("\t%dms", blc_score->reactionTime);
}

void blc_react_displayResultTooEarlyScreen (void)
{
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 75, 2);
  M5.Lcd.println("TOO EARLY!");
}

void blc_react_displayResultTooLateScreen (void)
{
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 75, 2);
  M5.Lcd.println("Too late!");
}

// Arduino hooks

void setup() 
{
  M5.begin();
  
  M5.Lcd.setRotation(0);

  blc_blech_react_init();
}

void loop() 
{
  M5.update();
  buttonPressed = M5.BtnA.wasPressed();
  
  blc_blech_react_tick();
  
  delay(MILLIS_PER_TICK);
}
