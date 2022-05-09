#include "ability.h"

ability::ability(){
    code = -1;
    cd = 0;
}

ability::ability(int num)
{
    switch(num){
    case (int)('q') * (int)('q') * (int)('q'):
        code = qqq;
        break;
    case (int)('q') * (int)('q') * (int)('w'):
        code = qqw;
        break;
    case (int)('q') * (int)('q') * (int)('e'):
        code = qqe;
        break;
    case (int)('w') * (int)('w') * (int)('w'):
        code = www;
        break;
    case (int)('w') * (int)('w') * (int)('q'):
        code = wwq;
        break;
    case (int)('w') * (int)('w') * (int)('e'):
        code = wwe;
        break;
    case (int)('e') * (int)('e') * (int)('e'):
        code = eee;
        break;
    case (int)('e') * (int)('e') * (int)('q'):
        code = eeq;
        break;
    case (int)('e') * (int)('e') * (int)('w'):
        code = eew;
        break;
    case (int)('q') * (int)('w') * (int)('e'):
        code = qwe;
        break;
    }

    switch(code){
    case qqq:
        cd = 20;
        break;
    case qqw:
        cd = 45;
        break;
    case qqe:
        cd = 25;
        break;
    case www:
        cd = 30;
        break;
    case wwq:
        cd = 30;
        break;
    case wwe:
        cd = 9;
        break;
    case eee:
        cd = 25;
        break;
    case eeq:
        cd = 30;
        break;
    case eew:
        cd = 55;
        break;
    case qwe:
        cd = 40;
        break;
    }
}

ability::ability(int num, char c){
    switch(num){
    case qqq:
        code = qqq;
        cd = 20;
        break;
    case qqw:
        code = qqw;
        cd = 45;
        break;
    case qqe:
        code = qqe;
        cd = 25;
        break;
    case www:
        code = www;
        cd = 30;
        break;
    case wwq:
        code = wwq;
        cd = 30;
        break;
    case wwe:
        code = wwe;
        cd = 9;
        break;
    case eee:
        code = eee;
        cd = 25;
        break;
    case eeq:
        code = eeq;
        cd = 30;
        break;
    case eew:
        code = eew;
        cd = 55;
        break;
    case qwe:
        code = qwe;
        cd = 40;
        break;
    }
}

int ability::getcode(){
    return code;
}

int ability::getcd(){
    return cd;
}

void ability::setcode(int i){
    code = i;
}
