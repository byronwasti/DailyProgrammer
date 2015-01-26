#include <stdio.h>

const char *msg= "Etvmp$Jsspw%%%%\
    [e}$xs$ks%$]sy$lezi$wspzih$xli$lmhhir$qiwweki2$Rs{$mx$mw$}syv$xyvr$xs$nsmr\
    jezsvmxi$Lipps${svph$tvskveq$mr$sri$perkyeki$sj$}syv$glsmgi2$\
    Qeoi$wyvi$}syv$tvskveq$we}w$&Lipps$[svph%%%&${mxl$7$%$ex$xli$irh2$Xlmw${e}\
    tistpi$fvs{wmrk$xli$gleppirki${mpp$xlmro${i$lezi$epp$pswx$syv$qmrhw2$Xlswi${ls$tswx$lipps\
    Irns}$xlmw$jyr2$Xli$xvyxl${mpp$fi$liph$f}$xlswi${ls$ger$higshi$xli$qiwweki2$>-";/*r$mw$m
    tistpi$higshi$xli$qiwweki$sr$xlimv$s{*/int f=0;//r$erh$vieh$$qiwweki2$]sy$ge}$epsrk
    #define printf(x,y)printf(x,(f&&(y!=34))?y:'\0');f=(y==34)?~f:f;//gleppirki${mpp$xlm
    /*f}$RSX$tswxmrk$ls{$}sy$higshih$xlmw$qiwweki2$Mrwxieh$tswx$}syv$wspyxmsr$xs$fi$}syv
    Qeoi$wyvi$}syv$tvskveq$we}w$&Lipps$[svph%%%&${mxl*///$7$%$ex$xli$irh2$Xlmw";


int main(void)
{
    while(*msg)
    {
        printf("%c", *msg - 4);
        msg++;
    }

    return 0;
}
