
#include <TM1638.h>
#include <TM1638QYF.h>

TM1638QYF module(2, 3, 4);


word mode;

unsigned long startTime;

void setup() {
  startTime = millis();
  module.setupDisplay(true, 7);
  mode = 0;
}

void update(TM1638QYF* module, word* mode) {
  word buttons = module->getButtons();
  unsigned long runningSecs = (millis() - startTime) / 1000;

  // button pressed - change mode
  if (buttons != 0) {
    *mode = buttons >> 1;

    if (*mode < 128) {
      module->clearDisplay();
      delay(100);
    }
  }


  module->setDisplayToDecNumber(*mode, 0, false);

  return;
  switch (*mode) {
    case 4:    //// +
      break;
    case 64:    //// -
      module->setDisplayToDecNumber(runningSecs, 1 << 5, false);
      break;   
    case 1024: ///// select
      module->setDisplayToHexNumber(runningSecs, 1 << 4);
      break;
  }
}

void loop() {
  update(&module, &mode);
}
