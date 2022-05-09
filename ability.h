#ifndef ABILITY_H
#define ABILITY_H
#define qqq 0
#define qqw 1
#define qqe 2
#define www 3
#define wwq 4
#define wwe 5
#define eee 6
#define eeq 7
#define eew 8
#define qwe 9

class ability
{
    int code;
    int cd;
public:
    ability();
    ability(int num);
    ability(int num, char c);
    int getcode();
    int getcd();
    void setcode(int i);
};

#endif // ABILITY_H
