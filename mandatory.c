#include "pf_utils.h"

void simple_test()
{
	TEST("no format", {
		test_printf_noarg("");
		test_printf_noarg("\x01\x02\a\v\b\f\r\n");
	})

	TEST("% format", {
		test_printf_noarg("%%");
		test_printf_noarg(" %%");
		test_printf_noarg("%%c");
		test_printf_noarg("%%%%%%");
		test_printf("%%%c", 'x');
	})
}

void test_c()
{
	TEST("c format", {
		test_printf("%c", 'x');
		test_printf(" %c", 'x');
		test_printf("%c ", 'x');
		test_printf("%c%c%c", 'a', '\t', 'b');
		test_printf("%cc%cc%c", 'a', '\t', 'b');
		test_printf("%cs%cs%c", 'c', 'b', 'a');
	})
}

void test_s()
{
	TEST("s format", {
		test_printf("%s", "");
		test_printf("%s", (char *)NULL);
		test_printf("%s", "some string with %s hehe");
		test_printf(" %s", "can it handle \t and \n?");
		test_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
		test_printf("%s%s%s", "And ", "some", "joined");
		test_printf("%ss%ss%ss", "And ", "some other", "joined");
	})
}

void test_p()
{
	TEST("p format", {
		test_printf("%p", "");
		test_printf("%p", NULL);
		test_printf("%p", (void *)-14523);
		test_printf("0x%p-", (void *)ULONG_MAX);
		test_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	})
}

void test_d()
{
	TEST("d format", {
		test_printf("%d", 0);
		test_printf("%d", -10);
		test_printf("%d", -200000);
		test_printf("%d", -6000023);
		test_printf("%d", 10);
		test_printf("%d", 10000);
		test_printf("%d", 100023);
		test_printf("%d", INT_MAX);
		test_printf("%d", INT_MIN);
		test_printf("dgs%dxx", 10);
		test_printf("%d%dd%d", 1, 2, -3);
	})
}

void test_i()
{
	TEST("i format", {
		test_printf("%i", 0);
		test_printf("%i", -10);
		test_printf("%i", -200000);
		test_printf("%i", -6000023);
		test_printf("%i", 10);
		test_printf("%i", 10000);
		test_printf("%i", 100023);
		test_printf("%i", INT_MAX);
		test_printf("%i", INT_MIN);
		test_printf("dgs%ixx", 10);
		test_printf("%i%ii%i", 1, 2, -3);
	})
}

void test_u()
{
	TEST("u format", {
		test_printf("%u", 0);
		test_printf("%u", -10);
		test_printf("%u", -200000);
		test_printf("%u", -6000023);
		test_printf("%u", 10);
		test_printf("%u", 10000);
		test_printf("%u", 100023);
		test_printf("%u", INT_MAX);
		test_printf("%u", INT_MIN);
		test_printf("%u", UINT_MAX);
		test_printf("dgs%uxx", 10);
		test_printf("%u%uu%u", 1, 2, -3);
	})
}

void test_x()
{
	TEST("x format", {
		test_printf("%x", 0);
		test_printf("%x", -10);
		test_printf("%x", -200000);
		test_printf("%x", -6000023);
		test_printf("%x", 10);
		test_printf("%x", 10000);
		test_printf("%x", 100023);
		test_printf("%x", 0xabcdef);
		test_printf("%x", 0x7fedcba1);
		test_printf("%x", INT_MAX);
		test_printf("%x", INT_MIN);
		test_printf("%x", UINT_MAX);
		test_printf("dgs%xxx", 10);
		test_printf("%x%xx%x", 1, 2, -3);
	})
}

void test_X()
{
	TEST("X format", {
		test_printf("%X", 0);
		test_printf("%X", -10);
		test_printf("%X", -200000);
		test_printf("%X", -6000023);
		test_printf("%X", 10);
		test_printf("%X", 10000);
		test_printf("%X", 100023);
		test_printf("%X", 0xabcdef);
		test_printf("%X", 0x7fedcba1);
		test_printf("%X", INT_MAX);
		test_printf("%X", INT_MIN);
		test_printf("%X", UINT_MAX);
		test_printf("dgs%Xxx", 10);
		test_printf("%X%Xx%X", 1, 2, -3);
	})
}

int main(int argn, char **argv)
{
	printf(YEL "Mandatory:" NC "\n");
	pf_setup_framework(argn, argv);

	simple_test();
	test_c();
	test_s();
	test_p();
	test_d();
	test_i();
	test_u();
	test_x();
	test_X();

	TEST("random", {
		// generated in python
				/* 2 */ test_printf_silent("Vh K%umC^%dc%s%pc27d%dH%pjYi[[#kc|d", -1115430841, -1637620721, "u?x`.ncpXG1ZS#..t+Qb{D-vh<", (void *)-300943048587783911, -1626096874, (void *)-6414900376965007189);
		/* 3 */ test_printf_silent("gw,.`>{^wm%%|c=$5Ap4%cwlFd%%,Hb%%4sf%xsjy%x.aeuNy", -93332881, 479490958, -480449386);
		/* 4 */ test_printf_silent("\\K@c\v?-O%%;S}@Q\\cU2%sK@+%Xv\n!\v+C", "'BMQrKJ~XUz0W}o}C\"\"AV`N&\"tck8xN0%|TZt*1<^99<,\rIlg-5)8:\vIw:T.^NyL\f.z\f5,Gg\\!Mh9", 280865280);
		/* 5 */ test_printf_silent("!5%u(\v%d47:u)%%)%d+0Z\"M%iN^O)KA;!G%x2", -1517620305, 957994425, -1353108932, 1539705066, 1584621443);
		/* 6 */ test_printf_silent("$c\f6 ^%cv%c%cx1%s`P67w%%ZD%u=.i`=LK%x:[U", 1192823969, 1119177507, -566430046, "T^?XgvM3xZ=+s4\vNB2<I<&dxr)J,j]){XEu6 vdK7g^)&R?0SE#zc", 279681000, 1860033794);
		/* 7 */ test_printf_silent("%pql&4^{Z'%p-|S\f,7", (void *)-2540235154361767173, (void *)962248100115878158);
		/* 8 */ test_printf_silent("j14+9%iD=RT0F!I%iCv>gR\"b^%i\"=~@:P)%%[RoA^N\nE0%i$`A[?%cZU^wd2L?", -1225678987, 1520225801, 233798223, -831585342, 1658552557);
		/* 9 */ test_printf_silent("=>z!%c5P1\fWm9%sbWTK\rg:|%XQN+NR)xaws%X=(#3P'g7.", 461561509, "&:/GXL\\Dz;e0E49I5O6_s7Ppi-fq\n%^MW\tttBO~Rj!;A\t0Avb@/D^.E6y3:j:\"u9#iFKq\t\t/}IU", 456600467, 1227863774);
		/* 10 */ test_printf_silent("N(~a%X<%i6%i\"u#-g)%pY(@&5%x~1<Elr%%%s9D+Hdy(LMc%u\tDm7nlZkOc%i;hI", 534347711, 730455846, 605709103, (void *)5733239181491811105, -1260783588, "&1{WW%EP(:V,OO$$ge+MO46k:B", -240907427, -186391009);
		/* 11 */ test_printf_silent("u0^kd\r~%u{ ]i\rbURc%p@%xH\n _R%c-%pmh[Ra?7Xoq%d\v.%Xd%i\flUBy", -234911089, (void *)-765617062277341037, -8845523, -535726021, (void *)-57426910887616364, -1158846977, 752144041, 1814209145);
		/* 12 */ test_printf_silent("@'6rPTy%ck-Q-b*%i!X|%u';/yN%pb}<9H,hG0_", -325965236, -1375227067, -902683175, (void *)8060890091150104985);
		/* 13 */ test_printf_silent("OY&7J#[np%%w17tT{%d'_\f15)=%c62jixUX1Cj%dg%dtj%svq)vB8q2%iS}>*~%XK_7k7\"xHP%d!_GDaF%c(zG #I\t4V\f", 1734665033, 1008753729, -1142909195, 2069142255, "X>T9j\v:fAd.QZ)Y pBd#%DMG dc)F:\fTc&W`eZyaTsJ\f8K8", 1849242176, -186730675, -2070278631, 97459293);
		/* 14 */ test_printf_silent("XF$' P3%x%c?ZFBj\"-] ~%i%c\t3u\\8J1%c\vh[\"%x9_m7k%paW%xP4* .%%(__Y_ku[d%xvP,B5", -326864848, 495391734, 258111594, 640600979, 223257135, 1076635975, (void *)-3802718357308484361, 32835800, -1900670888);
		/* 15 */ test_printf_silent("me\\2}%dl%dE{i8dD%p-tiv\\8IoPj%srv,!'jNfu%%\r3", -1622656480, -1151270098, (void *)-50754720408529673, "Cn\fi67\n>BA5}&+;OzVL\fbeJ#\r^s{4vNA!#\r'58*,)m<j7>C[Hlc~\tmq!o");
		/* 16 */ test_printf_silent("f9%Xu f%%\rF0 Dl%d3\nI%x:M", 596629650, 1213706524, 879043322);
		/* 17 */ test_printf_silent("\n :%u9%xIQ)ac` ", 598243007, -1342655498);
		/* 18 */ test_printf_silent("xL\r%s{\n`M?[@`%d'5g[", "U\f.;x$MSu5g\v\n?DKJVx`|q?n67QYxU\v\\`T8lWS\rpU/HTmo9]h\vL\rvmqD", 1225323477);
		/* 19 */ test_printf_silent("+-^ayg_%dZforW\"%d=\n,f@9'zJ9%xN!:#%Xrw?#%d{>wu]", -510087746, -1806709088, 430697683, -1290281565, 1929131445);
		/* 20 */ test_printf_silent("%x%xD~%p\fy?CAK%p\r\t/}-bIc+F", 1422667859, -557659020, (void *)-6964285720701591557, (void *)-2313215684218560099);
		/* 21 */ test_printf_silent("W?7%is-cVu(%dhT*=2En\f", -164753842, 124043031);
		/* 22 */ test_printf_silent("/{%i^~jepToE]8%iAN)%iYDVM'%x'6mJu\f]8ec%p ;l \f5e%pkaHl%u'xr%u'Z(%dk[%X5V", -988370313, 1785059932, -1336680492, -1523397771, (void *)6123934514872268094, (void *)-5678958662027555090, -850970948, -187504939, 1977126295, 303585153);
		/* 23 */ test_printf_silent("7%%mj[]/&%sR29n?Z\v%s%xk2PQP~ +@#%Xk D-%xAY%skb_G*1i%xO\nr", "`+5#P,q|=Z$\\Pm\v^l6*\faI$*<GCUp\fnZk)^NtyHv/lu(_1B\v=jTQ#3]\vH]D=q%5j1,BFh36*vJCB6*wE(", "@r]ETlZI\"rA\\~U^\vzF?j3T+F>c:}3I,#X", -601366507, -2072545420, 873815463, "iOURuf0RFz\v.+\fA,5V)\fTs$0qX/pd\"`SoC,,M\nNS\rN\v!^+k*I}~6Oz?89mE\"pC,j Ul\\m'MB?Oc)li\r;:p?b\\ ppS[=\fg$\v7\r", 1737130894);
		/* 24 */ test_printf_silent("#1%xW\tdR%s\\!/6\"%X*q#z8Ck=bT%c7\r\fHW{\\cB%XB;A,7WXqhl%xCW%u0*g4", 559128452, "'#~OD1\f+hq9:Q<aSB#\r6cypdL9F(l#t19xm\"~IW!=", -1115535778, -1331813820, 254665813, 1904981061, 1734124076);
		/* 25 */ test_printf_silent("kl||%dYz.?\tyS%pgY;%dp%pz\\,<rSs@d.%i+K-}j\f[_", -978220273, (void *)-7662396572475058231, -930752902, (void *)3930252891334551157, 1924019120);
		/* 26 */ test_printf_silent("/D%d5%cBH&k6Z%d~a[b%Xy]a\fT(a9q6%xTb >B1S$j\v%sG%xe\rOr\t0%x:a[f@Z)D\r%%Kkn~~\rZ)s", -251340755, -8564267, -688603235, 1961692401, -207680499, "e_wz6;#g`fL)P#F.SA=H$|GgkM5hNFlH&xlzLN&'H\v{2QX3*[mgDgBtSFkc:IlSk2\"SP[9;%my_#Q~kB2\nb'i@\nQKAq s,RQJ", 1579296903, 1182521840);
		/* 27 */ test_printf_silent("mOx%c+5wJ~%uZPjo*y%s\v\v_9H%%^JVY}7%%%s(\fk4s-9\"t%%|g\r;+w-+R%X\rty#%i7+M", 734214073, 1224230558, "FE.8;?o,@.@B;cBOMRuh.1?+<9 olbbMXk]#l:CxL.t!vnn<cL\\fV>r_AxV<s\rJhY(H\nMo<(gS;Y_$lT=GU (y3g]'aDgZuOJ9M", "Z'\"O\nHFA\"mvY*eKET%-vjt\vD@S", 1811355928, 1916570482);
		/* 28 */ test_printf_silent("%%([>@%X%%w%%\n}%c\fzKa_}SqH%X:V`>ZA`0", 1762545346, -42942965, 1351447336);
		/* 29 */ test_printf_silent("z_6Q^j0%%mvUdL%x!ZdZ\r0%%8eIl2~0(l=%XvM{A$7c.R", -797958007, -1016630184);
		/* 30 */ test_printf_silent("\"<cx>\\DqDY%s'?%u0T8x\rx5vm1%iNOz3zwh.Zf%dOYydZB>%s%cs[&\\sxT\v/~%dvUB-Q;y", ">qW(qljgV^Z'\te{d5r\n}D-F", 944882111, 859418090, 1368660116, "97Q_<(pJadbgx@b\t'gaYL{6[T:[Lhb2:DqV>", 1297007703, 551257433);
		/* 31 */ test_printf_silent("M{l*l2%sqSs$/a%XWJ}!Mid;2%cJ`435", "Ef?F&:;6\vIJ\rBi@", -1047863017, -1432196853);
		/* 32 */ test_printf_silent("A\tW\tH%dT%c.4CQlSD+%xvk%sJLB /*@`uK%p-bh VT(q]%i?Lk.axX%s+\fDX{6F`%x21EO5I%pb%uxety", -778609013, 1610806931, -1614037629, "[C=oz\t/9k1J,:JVVNFxoVmv\\q&S;5--(4E$rXGV8$}.L]\to+6`EmN3KK#3Y8D]`| AXPC\t?7g<z?b*R3PwM+", (void *)2199543634186869382, -2140588016, "3<><9\tgR\n1fG=hLNyCOqazQ(i)E}4>%Q\n.K\vvvi:Y.@?1\nhl?{", 1848058249, (void *)4952074215048350601, -1512776297);
		/* 33 */ test_printf_silent("r;PcddQ\v+q%cdT+%i13", 2085438450, 450581348);
		/* 34 */ test_printf_silent("8$(W2;x%p_==$ %%M_ N!1Igg%ca%%sL%sp1'fRw!U_%cNGFW?7Tr\vi%xbwp+q{%uto\t6zA%pY2V", (void *)-6873388092560676921, -1980695930, "lUn\\Y(|\"p\nfD^5K~{*]kI3=N(A:g-6~\n_5Lb^+:Na,Q@/jG(,;GkvUj\f\nKhya\n|t(?en =;\"}7Ord7\v", 1102320496, 2049241059, -1194906311, (void *)6850319352329861855);
		/* 35 */ test_printf_silent("o%p3&iC-%uk,=$l6%dP.", (void *)-2987323518723098214, -286837085, 993151222);
		/* 36 */ test_printf_silent("fi[%d%%e;5^[]m<%i.o[+%c] vD42yg%d!%xx%u$kqf<W7Pq\"", 829627383, 1663685726, -800670375, -2073002311, 64489223, 1793496125);
		/* 37 */ test_printf_silent(",'J_%p%%T*{>G~WjH%ipOE9}1ir%xcHM%pBI$ut`.AF", (void *)8067256497095423999, -907523266, 1717790813, (void *)3459000093192490441);
		/* 38 */ test_printf_silent("U@~J%XZfw[v!%dJxv&Mxx%sz@P\f`'9.%d)SDrJt/lL%Xr!Lww\rb00%uN\v+\fL(%up\\l2pnwV%c.\n6[@%dEv(", -2102993896, 1958781509, "f\"LOj0Rki?{?+FRcY>sY~#r^7rSe&[wySH\f/m;38U})6%^=S=iFVr9TeM|G@35\"nhZ,*z8lQ/u \f5_sF%{6po^RMep#:thDas", 1010103646, -725145530, 690540962, 938430998, 1533271569, 1748331396);
		/* 39 */ test_printf_silent("|'Xr;C%p[D(%ddIG1r%X%i4)Y\r%s4\fz1%X+X]o/AfO;S", (void *)1855337955380873800, -1188362649, -603166479, 2049951081, "fAoO-;:weuE", -649392901);
		/* 40 */ test_printf_silent("w*)F7YV\tjh%x7c+-ls]%d>H5t\fG>v(%xwjC1r+ye%xdoV(Z,xy`M%xE?w{X4\"Q1%xf9%pv\\X%uT%p%doe6b!", -1576461442, 619080848, -1086990572, -611478682, -1325802531, 1783649070, (void *)-8879113952127746725, 1508320177, (void *)-1943708966156352324, -787219741);
		/* 41 */ test_printf_silent("eK#J%dC'kH%xUHr~={%X@~_%d%%@fq\ns|)S1_", -1485453433, -1356907351, -1387295800, -1688915274);
		/* 42 */ test_printf_silent("`[?fm[%p%s83)%xnH91We3%p\td+D\r{4?%uMPz9%c'95DeO-|I%p L|\\+%ujFm#b\"E", (void *)2278447502355645466, "\vZS9}<\"NQOmp1SkIr!)_.5Fw@Ruz$RXAss<v{mX2mKk!fs_%mM\n@'\n)4E}`ij*`wJ&@by\f$7(Y![\v\tL65", 911071035, (void *)2091265487201211376, 1279442995, -1176042850, (void *)-1199332335382991360, -44214487);
		/* 43 */ test_printf_silent("uv6,q%p\r,(\"Sqb\rr%u=k8b%XL4LW%chn\fro%ir1;;H2fe%d,@g c%i\fnCjX %d+%s|s", (void *)-106154290640204971, 1031711661, 1914373341, 352275763, -2082058355, 2055314552, -751114228, 1804297473, "");
		/* 44 */ test_printf_silent("RvR~]'%pI.Hlu`%sHC !%%R_%%", (void *)8771849979759579533, "mFG=;7'jJ6M)A:$LV^jQUP&Wt\v@^f'o");
		/* 45 */ test_printf_silent("%XmN%p>)\\,P~%%`xt6h}w5%u%p!@", -23211567, (void *)9104831995795164209, -557978140, (void *)3036594385274651054);
		/* 46 */ test_printf_silent("M`(7E'\"n`Y%%)  -N \vNk%xZo`.'%xlw-?%st\fC%pY^M%%H%dX^)MyU+%psm\n\f <b2m%dK5\fPxHV`w %u", -2057988404, 1575535980, "XQbr5!|R :_]w#&qBA/\t&31bGua\tfS\"VDk/UC3m{rP;\n^F)pV~A#/m%@5:14oo}C|3jf", (void *)5787840732239503721, -2079071950, (void *)5212894576408201449, -1642940044, 489725032);
		/* 47 */ test_printf_silent(">9$CT-v+^%s%p@TSG%p\fP~.z~q;%u@$b^3Q01f$%iH+ -SI!P;%uz", "u<XwKP4q{VT2c<][iv9Vdu42(N{#L!nkxGn)=z\"{", (void *)4764878579409548330, (void *)-4308401681117117323, -1243950129, -994322184, 1079028839);
		/* 48 */ test_printf_silent("lCE%uZo8f)),e}%%j:_%d`vkj^%d\f@%i\n>i%x3\vK?X(^[rV%iv/4r0r%uS%xn4L4lO%XNyf{", -1053592718, -889464098, 1214821708, -10044951, -204684412, -1113977812, 71164929, -1112129749, -1689111557);
		/* 49 */ test_printf_silent("%u%d%s&", 243076202, 1313667945, "Z-p\v@h^f9R;\".Z\"6uK\\dn!@\nppIIE[Z4f_oEVXkCS@\"bY?DN!V^f=\"W7y5x:vdV\t");
		/* 50 */ test_printf_silent("tGw]vf%X?zRUM@Q{%c#L%ds}gHp%cmttNyX", -1795155939, 710092340, 1941584077, -1777561307);
		/* 51 */ test_printf_silent("fMp\n4%s/R47n*[lr%p^%p?%sx9U%dA$?lkV<A%saS=6\fFa%%/tPsY<n\\1O%xV`&%XD/ql$I`E<", ",iE=<D#[HCfG_t\nyq+^;/#'L9lfI,<M)LG74U5rLT|FT/HOLk7R@./:1bD\f(Tga<6cE$j0YOO!EDmUx@,``'S>4N<4yauEj-:(aJ", (void *)4607374356776754794, (void *)2903624049582613614, "\n,\"tWFc}k#G;_nltadZ1./]c3@U%Mlf2Uh\\\fx|'^iN/\v\n`\nC2/\vf!F=;8,Mz\"TC \n#-V+YH\r0HSHB' r](\v", 147908957, "'K@w&BK)\f4ZF6Vo.*TqR1GNS#\n)k7__s?\nnF[6^2Z!6[\"]Ryfsnv\"2'qA^4\t=Wm\r]'\t o)jUfKTdQ9sk5zm{)xlp+<&@8E~", 1236448505, -607441862);
		/* 52 */ test_printf_silent("k%d-!\"{}-w{,%icPQ'Q\ru<%c,`%X~AaP%u2I<\r", 1622762190, -1453237229, -872599820, -1189981548, -1291841608);
		/* 53 */ test_printf_silent("x^Ehi%Xk/%X^nv,gXn:8M%c'^8D%XM%c.fpe85lO0%s pE.7MW6P%xn\nOMGg.I%dR6%%0\f", 1973417585, 581797032, -248355576, -1786620302, 1350313955, "~LRtU@:SH*Vp@qjxI$y#h(uN4g+JG6[D`li.>:D}GHj+f\rHv\n~S*>Y", 1695958983, 1131698967);
		/* 54 */ test_printf_silent("\nH.%u\vx;s^2%pu*z|hts%uH%%%%\v%x lC tR,q1", 1764708532, (void *)833829165756577922, -1855160086, -1697791733);
		/* 55 */ test_printf_silent("w%ijTG%dzySWmA;W", -844161777, -500740255);
		/* 56 */ test_printf_silent("-CdM)%ps=fOZHyq%dp*%u-\v5}c~`TXB%p FlQg@h%%9,jEM$\tD4J%s;!ES%d.j<UDY~E%p(E}+H')o0Q%ilBA!WO%%e?R", (void *)3978662942094118907, -280607371, 1636124784, (void *)-1469515376632402432, "umm&U^i?+\t7:r|^ErLx1)f.-gQh;\n-tr+yOs[xvTV;/\nf\nC}nT:\"HT|Mt<=+&[vT\\ii%w<Em(35iC", -1625322412, (void *)8379716842285691852, 1278847044);
		/* 57 */ test_printf_silent("\nP`[w-8D%i\r+e\"F%uVr':mWvA2\r%XyZo%u0],oiU=d%duA3%ss#E%X(Hs!%XNrj%xUo?x", 1159907384, -1851632696, 670536088, 1231539398, -171850330, "$r?v\"DD8fa#rWwm_\v]E", 473870984, -1522646607, 1153710628);
		/* 58 */ test_printf_silent("|c'=%u-f(GBv5M;%cJ", 274651187, -1657590480);
		/* 59 */ test_printf_silent("xra:%sWU\fW%s\nX}Y9[RW1]%xm%dTG", "xtJdTF>@nF<q'l/a`_NHUm_x", "w5H[7Y2}%fiL9gRo1~=:\nt!q6H*\vhqg<RO,%cl\vkm3Wt<wJ*rY*^{l\fJQ\\mY#<>Oh+tx\rc>]:Y!zJ", -1522636801, -2140454479);
		/* 60 */ test_printf_silent("n<?'K\n>S\\%%6;Yv~b]>%sb!~nL\f%X4!!v.+/{%XLJ}qW:q`M%i=t)?Av%pX", "VQ#Q[e\nd:{su.\vEs+,7b\rer!.iUUD0j", -867311922, 1301060595, -45382846, (void *)3986221675534646799);
		/* 61 */ test_printf_silent("81?F>Ho[.<%cU|%%G sd", -1001059194);
		/* 62 */ test_printf_silent("/oxAK^v%p3{|_\vJ\njB%sZP3.*R%s%X\t_+d%sbukmy%X}9F+D=<; %s:ZtP%pK`VF%ix0-H^", (void *)-6002775150557539437, "8#gbwUo>)z\f6j/-?qG\v,\vL=xm:A'}{DA./lqmT~ N0`p~nz#We:rYrTb", "FC]RCJTeJ8hL*&ZYvfM\r$a.J|v~tW2u?\?jj(]FP{z-oZ(a\"p.<pM_>VQZ\nv2MN~Y\f<<0#&9P1wx.sDb", -930421107, "'2u_gE\\7w5B?6^:\"", -1261650538, "evGpX.9S@yL#q~.NY/m8cxN;4@\tKw-Zs6m2F2{p]\fwau-^^ qGt\"-A,~cP\n:Uj gr8X qPH\v\nEsi\nw1R43,a", (void *)4659601106544243418, -525487933);
		/* 63 */ test_printf_silent("mZJQ&d%i<|%dvA)%i0 _wvKk%i,^Q-{k@%x^l}pOw?%u1E$4%s=x%xUUhuU%pj %%-KAWr\t~p", 277689401, -387249896, -1527249466, 488076371, 1284255818, 60043591, "Q8j{sv\tc`-V+t<C@M5UOt?I{xPI]Z#SQH\\D}/dxJmW'-ADf%td~|iCB:7UTWt\v}gL-1Ak[Rk.2sc<? oD\fw1%Mv9z\\Cbnx$ ", 718839256, (void *)-8227574428492244549);
		/* 64 */ test_printf_silent("%u\vu{l!j%x%uH%c(\\'Tg&\\", -459465505, -1645290723, -1522213444, 161055794);
		/* 65 */ test_printf_silent("bE^g%scQ,wy} u>%p@ fsos", "0AUe`c\v?YiMn\tOIV+ZIfTE!'}Fo6IQ5h", (void *)-4536637288307598351);
		/* 66 */ test_printf_silent("76Pq+%u{B%XE'hKZ\n>JJ%%;q\taB)sKz", -1629735704, -797560375);
		/* 67 */ test_printf_silent("[ >MjxqYwr%X\t%cMl2%cnWxV9Ehz", 698163500, -625523582, 1522241373);
		/* 68 */ test_printf_silent("o`pw9}%%Yi%ux$X7p\\I%pW!L1XP+%s\\>wmCf$d#", -665791751, (void *)-3046175778407725266, "W`%,:Z+j:\"nW7(0R!.O\fH>-Qe5 &Nu$t#pajWvB9;\f+Eo:]c^E\ffRB`/u`FqE08Y!NH1BK9WJRH`G`&uL\\\n*A(o");
		/* 69 */ test_printf_silent("*tRN_%X,%ucUAk%sJ}%x5Xf]%x=]+7%XBe", -1003296069, 1481680392, "=<vc\\.a\n4sXV5LZ- uCK;y!0@f.;8eph)))H}ZBmv+B}7X2-!SbDj=}e]", -308241446, 1000148369, -841030530);
		/* 70 */ test_printf_silent("\f\"YTr)Gy%s%p9C7b>X%dG\r(kdT~%XiLH/r<a\v%i_4-lS%c'U\"PVr%d!7i \r@R:%XQmIv]3D\\rp", "%aU\"5\"/VZxm}yrY#cM>PJ)sj=v?kH", (void *)1875157254558533193, -266637697, -328398473, -770528437, 860128188, 482682564, 1848490052);
		/* 71 */ test_printf_silent(";=!H?I(~%xEE>.([%%&~7<-\t", -327921897);
		/* 72 */ test_printf_silent("<^=+Q>%pP%d&\nx%%!\vpQB^%sj,FaCFU6s\r%d\n8/p{?kgRY", (void *)1215770147187726507, -1014058661, "5KyGbUd,8i,3bV-wG[,MGS&|\v<pb7\vX)zmA6M |vS`wF)YU>S{eb:dEDY#>/>}(kpF]fKiu^~a.#C:]_RemBA,1^\tc\f3KF_pm\\u", 1904487243);
		/* 73 */ test_printf_silent("/Q9QY$%caU3%su+TNW%c\rsu(-ldM\f3%xd>BnU[%%YGY\t^V0>.", 1230481832, "H2<\rp(iDUK2B5c-THm/A-Um08WHF~,]/>y\\i?N<fyM.`o+hdLr", -1631388234, -815764746);
		/* 74 */ test_printf_silent("KpY '%X%Xg2Y'\\LPzp%s?b&?j >", -323122810, 1863245798, "z\vyMds<[:lT->{6e0tmP]");
		/* 75 */ test_printf_silent("L+b!\f%%,%x)B\f%%N$Uu4%x", -672600395, 371258720);
		/* 76 */ test_printf_silent("-\r#%X{f^%c<{l%d=;qy|/q%d),EU[RN#%dQBS~xxyJ %X*%c\\9t%cZJI", -1848634204, 121335343, -764835785, -1863880242, 937741081, 1711279683, 200529858, 1167388956);
		/* 77 */ test_printf_silent("=Z%u%X/Bi0dXB%%%xagHz>D<H", 2110344173, -1934090178, 722406999);
		/* 78 */ test_printf_silent("CbC3A]~V>T%%!N:b6O5{%dVc `}2{0%X\"V>k%s\v%%H\\HbN@%ch\",SAxy\n", -1901551226, -416655752, ")r6]#r4TB0Q'%\r|\n.?$1q`V2@MI\\j%lU_j}~@/urwux$-\ngiawnT@", 337484608);
		/* 79 */ test_printf_silent("]_ )%xuiV O\"x%x6POP%%%u$^%uw%sVL[&E6KNLj", 1093232088, -1814979682, 1139005711, -57616491, "Ji|R32X~taV7[KqXO%o\"=G9r~^\vR^MJ\ntuA|v0# P7A(e\v'_ ~\nuyc\r.bPgNA, QqZ>CKs");
		/* 80 */ test_printf_silent("B!C> %sR#+fAnjz`f%d)*lhY]xg%ua,/\v\\#evb%uF4@]%uKDtZ\f8uE%xZ!=?70<\n", "i7Ya6\tv\th&O6=v$e)d5ErAsLE:", 1466612901, 523556016, 240024981, 1604794965, 1597131506);
		/* 81 */ test_printf_silent(";%xIK%so/YUa", 776063814, "'RR\vl0aJ\r3edCMIr\v(PM_eMUPHl\t\vhN _D)cG[{Z<Gj\rq}|<{(_nOv.:X[n, 10<\t<w.Q_>~Z~");
		/* 82 */ test_printf_silent("^C\vz%XFUbl\t9e%%L*;V^~Ki%%%cUNDE$%X)yxH8]", -1577142795, -1078041562, 1298315499);
		/* 83 */ test_printf_silent("%pNO8D%X@rte\r%%9|%daaM`zv7n#?%uHi:\n:4d%Xd0!:v\fMSsu", (void *)-5371520030924673248, 429058734, 495977011, 1199084357, -2093353775);
		/* 84 */ test_printf_silent("7\tKB\rO}9zb%d\nP1H%pca]&#l6;|;%df{pZ%i%sie-%ib'.<'%XlRp&9", 57905752, (void *)6627975039619783807, 139011214, 1445606210, "sY|DG,7u4~J/ZHLt :\"u,Jq9$", -705922337, -1859058720);
		/* 85 */ test_printf_silent("%c\n&P 2!Jn%dd&6ne0RNh%c`A{7%x%sUS&}D2>'c", 592968654, 1136173292, -1175165124, 367815285, "\\ZJ_G\t\fZrH\ny\tBQ4WC4#! )/ko4HF\r~_rJ=y`0`D/Cr0h]ru^}/xUTlKV_stiWbL5TSw#d-1");
		/* 86 */ test_printf_silent("\v%x\ra#F%xbX2;lj]w}%%\rh$\tKng", 1050000727, 1286261331);
		/* 87 */ test_printf_silent("Hl+%d->qL[*\vly%ihn%s&\fg3%u]x2aj%pqg%xwLE^z^4", 262254544, 1400667896, "09Hu(b,)Gq<3$Au+vM2Idw!nlNB`zZ@ul\\=\nyg bf\n>z:e", -972508062, (void *)-1533414157561742628, 1397409424);
		/* 88 */ test_printf_silent(".I\njy2%sg%ulP;iol>", ">%(Db)8-,e~t\f!j\fc3#1$x^V/a^s\\}'r^", -276431954);
		/* 89 */ test_printf_silent("D%x4]}k8uo%sx]%X}%dA'-1eB", -1178968121, "IaY7X5Ue)(3L\vZ", 2104370470, -1748219571);
		/* 90 */ test_printf_silent("-%%P}x%X@I)YF%i%d!h0-.$%dE", 1990994938, 70444162, -2046247302, 795664387);
		/* 91 */ test_printf_silent("RoEd-%iVsMi%dB%xv-vc%sy5n%d[iAyKn%pQ$o|qs%%]dk%c,M", 2068906974, -2022286169, -930387554, "3^hDnOy5fg$V*yBct=iaSNDv7", -435522757, (void *)3714494153435208013, -1617625386);
		/* 92 */ test_printf_silent("K,[\\%X_3#WiLv%i '`!rEuW\nx%%.z$.%%", 506567761, 1242388054);
		/* 93 */ test_printf_silent("_{SJ4Bhl4%i8}|CXh\"H37%uMk's!%pJ%s=6x%s%c3t'wY#3\\!G%uS 5", 932368757, -785469890, (void *)-5411204044673672663, "]<'*j>U%m%qs&1$q^UlFxg]jB{Q|", "E*&EZPwB!)judNY[Fywk", 346728107, 67524724);
		/* 94 */ test_printf_silent("~%uRD%dh;Qd%uVlBQ(<@T`[%x?h%uBSOFE>h", -1710467280, 740339802, 777689872, -485310849, -1381105863);
		/* 95 */ test_printf_silent("$mtf9e4%x%if\\ou;&%ibn\\xP%%0pWI", 612995910, 301397611, -1994762074);
		/* 96 */ test_printf_silent("SC /%p:ZNL2~*]gZ%XK<fx}5qM3K%xL(smo{}%p{EY\n%iMFw%u.$B KM%c|Y.h'(..D%xXQ5", (void *)834664428966317185, -795698696, -1986484861, (void *)-9134183706859978035, 1751946815, 25172632, -859572487, 1084541662);
		/* 97 */ test_printf_silent("9`!S?%xu\nIt<R+$S%%%xH%s.%cz{ik\ty{b%s`P]Xs%ct '(J8%i'%%,r", 583504572, -1320124800, "\fb9@:(;x5pm1w%dq}Q_Ux\v4,F.CbRWzeXIcIDmUKzBc>yKlm\\GkkiJzwNvyYY[t4'L", 304354961, "7[iHSNUArlbL", -392063003, -1218162938);
		/* 98 */ test_printf_silent("dgw4t=Ec%c%s#-Ce_Q", 2030466714, "u(Cx#RuZ~dh>r[yWj4g3)fNI\ngP");
		/* 99 */ test_printf_silent("=*$OZu\feF/%uB6|0NbT:w%X_I5%d^2A [\fFP9}", 1163957016, 747783650, -282821866);
		/* 100 */ test_printf_silent("&%%zBQG[8 \r-U%d&Fz*y%X QiJ8%xn7~s%XFO;Q", 2135060910, -2141058124, -360715572, -523973798);
		/* 101 */ test_printf("s'M7'W`Ib%is /$5H>%c#M\t%iKW*_:lcp%cfA1yFh3].%xksp%%n(Z>/%X+t$U%s%%ic[%xDZy{ 2]vb<", 1262021813, -23431571, 844934154, 1345063363, 1472607803, 1462434408, "tnb$y~\\Rgc\r", -1356849478);
	});
}