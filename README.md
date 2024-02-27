# Mad-Pascal

[Doc PL](http://mads.atari8.info/doc/pl/index.html)

[Doc ENG](http://mads.atari8.info/doc/en/index.html)

## Introduction

**Mad-Pascal**  (MP) is a 32-bit **Turbo Pascal** compiler for **Atari XE/XL**. By design, it is compatible with the **Free Pascal Compilator** (FPC) (the `-MDelphi` switch should be active), which means the possibility of obtaining executable code for **XE/XL**, **PC** and every other platform for which **FPC** exists. 

**MP** is not a port of **FPC**; it has been written based on of **SUB-Pascal** (2009), **XD-Pascal** (2010), the author of which is [Vasiliy Tereshkov](https://github.com/vtereshkov).

A program that works on Atari might have problems on **PC** if, for example, the pointers have not been initialized with the address of a variable and the program attempts to write to the address `$0000` (memory protection fault). 

The strengths of **MP** include fast and convenient possibility of inclusion of inline assembly. A program using inline **ASM** does not work on platforms other than **6502 CPU**. **MP** uses 64KB of primary memory; `TMemoryStream` provides usage of extended memory.

Variable allocation is static; there is no dynamic memory management. Parameters are passed to functions by value, variable or constant.

The available features are:

* `If` `Case` `For To` `For In` `While` `Repeat` statements
* Compound statements
* `Label` `Goto` statements
* Arithmetic and boolean operators
* Procedures and functions with up to 8 parameters. Returned value of a function is assigned to a predefined `RESULT` variable
* Static local variables
* Primitive data types, all types except the `ShortReal`, `Real` type are compatible. Pointers are dereferenced as pointers to `Word`:
    * `Cardinal` `Word` `Byte` `Boolean`
    * `Integer` `SmallInt` `ShortInt`
    * `Char` `String` `PChar`
    * `Pointer` `File` `Text`
    * `ShortReal` `Real` [fixed-point](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
    * [`Float16`](https://en.wikipedia.org/wiki/Half-precision_floating-point_,ormat)
    * [`Single`](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) / Float
* One-dimensional and Two-dimensional arrays (with zero lower bound) of any primitive type. Arrays are treated as pointers to their origins (like in C) and can be passed to subroutines as parameters
* Predefined type `String` `[N]` which is equivalent to `array [0..N] of Char`
* `Type` aliases
* `Records`
* `Objects`
* Separate program modules
* Recursion

## Compile

    fpc -MDelphi -vh -O3 mp.pas

## Usage
[WUDSN + Mad Pascal](https://forums.atariage.com/topic/348660-wudsn-mad-pascal-quick-hack-increasing-usability/)

[Mad Pascal i Geany](http://bocianu.atari.pl/blog/madgeany)

### [Atari XE/XL](https://github.com/tebe6502/Mad-Pascal/tree/master/samples/a8)
    mp.exe filename.pas -ipath:<MadPascalPath>\lib
    mads.exe filename.a65 -x -i:<MadPascalPath>\base

BAT
```
    <MadPascalPath>\MP.exe %1 -ipath:<MadPascalPath>\lib -ipath:<MadPascalPath>\blibs

    if exist %~dp1%~n1.a65 (
	    mads.exe "%~dp1%~n1.a65" -xli:<MadPascalPath>\base
	    if exist "%~dp1%~n1.obx" altirra "%~dp1%~n1.obx"
    )
```

### [Commodore 64](https://github.com/tebe6502/Mad-Pascal/tree/master/samples/c64)
    mp.exe -t c64 filename.pas -ipath:<MadPascalPath>\lib
    mads.exe filename.a65 -x -i:<MadPascalPath>\base
    
### [Commodore Plus/4](https://github.com/tebe6502/Mad-Pascal/tree/master/samples/c4plus)
    mp.exe -t c4p filename.pas -ipath:<MadPascalPath>\lib
    mads.exe filename.a65 -x -i:<MadPascalPath>\base

### [Neo6502](https://github.com/tebe6502/Mad-Pascal/tree/master/samples/neo6502)
    mp.exe -t neo filename.pas -ipath:<MadPascalPath>\lib
    mads.exe filename.a65 -x -i:<MadPascalPath>\base
    
### [RAW](https://github.com/tebe6502/Mad-Pascal/tree/master/samples/raw)
    mp.exe -t raw filename.pas -ipath:<MadPascalPath>\lib
    mads.exe filename.a65 -x -i:<MadPascalPath>\base

## Tools

### [MadStrap](http://bocianu.atari.pl/blog/madstrap)

Simple Atari Mad-Pascal common project bootstrap.

Source code at [GitLab](https://gitlab.com/bocianu/madstrap)

### [BLIBS](http://bocianu.atari.pl/blog/blibs)

Set of custom libraries for MadPascal.

Lastest documentation always at [GitLab]( https://bocianu.gitlab.io/blibs/)

### [pasdoc](https://bocianu.atari.pl/blog/pasdoc)

Custom tool for generating documentation from pascal comments in units.

Source code at [GitLab](https://gitlab.com/bocianu/pasdoc)

### [Effectus](https://github.com/Gury8/effectus) - Action! compiler

In new version the source code is generated by using Mad Pascal cross-compiler, which is further compiled to binary code with Mad Assembler.

### [Game tutorial](https://github.com/zbyti/a8-mp-simple-game-tutorial)

Simple game tutorial by using Mad Pascal

### [FiDL](https://gitlab.com/bocianu/fidl)

Display List program editor for 8-bit Atari ANTIC chipset

### [CutAs](https://gitlab.com/bocianu/cutas)

Simple binary data manipulation tool written in javascript (export to Action!, Assembler, C, Pascal)

### [Bocianu's Atari Toolkit HUB](https://bocianu.gitlab.io/bathub/)

CutAs, FiDL, SprED, Sprite XL

### [A8 Mad-Pascal Window Library](https://github.com/Ripjetski6502/A8MadPascalLibrary)

This is a text mode windowing library complete with window controls and modern gadgets (widgets). The gadgets allow you to build input forms that use buttons, radio buttons, input strings (with scrolled lengths and type restrictions), check boxes, progress bars, etc. This allows you to build applications with "modern"-ish interfaces.

## Projects in Mad-Pascal

* [StarVagrant](https://github.com/MADRAFi/StarVagrant)
* [MadKingdom](https://gitlab.com/bocianu/MadKingdom)
* [zilch](https://gitlab.com/bocianu/zilch)
* [justpong](https://gitlab.com/bocianu/justpong)
* [hoppe](https://gitlab.com/bocianu/hoppe)
* [PacMad](https://gitlab.com/bocianu/PacMad)
* [k12trailer](https://gitlab.com/bocianu/k12trailer)
* [gr10](https://gitlab.com/bocianu/gr10)
* [oldmansion](https://gitlab.com/bocianu/oldmansion)
* [artur](https://gitlab.com/bocianu/artur)
* [jcq](https://gitlab.com/bocianu/jcq)
* [Fujinet udp shoutbox](https://gitlab.com/bocianu/fujinet-udp-shoutbox)
* [speedway](https://gitlab.com/bocianu/speedway)
* [chessnet](https://gitlab.com/bocianu/chessnet)
* [gr9Lab](https://gitlab.com/amarok8bit/gr9Lab)
* [SortViz](https://gitlab.com/amarok8bit/sortviz)
* [weather](https://gitlab.com/bocianu/weather)
* [cart builder](https://gitlab.com/bocianu/cart_builder)
* [Mole](https://github.com/GSoftwareDevelopment/Mole)
* [SFX-Tracker](https://github.com/GSoftwareDevelopment/SFX-Tracker)
* [SFX-Engine](https://github.com/GSoftwareDevelopment/SFX-Engine)
   * [SFX-Engine-example](https://github.com/GSoftwareDevelopment/SFX-Engine-example)
* [MIDICar-Player](https://github.com/GSoftwareDevelopment/MIDICar-Player)
* [heatmap](https://gitlab.com/delysio/heatmap)
* [sinus scroll 2x2](https://gitlab.com/delysio/mad-pascal/-/tree/master/demoEffects/2x2%20sinus%20scroll)
* [Flob](https://gitlab.com/bocianu/flob)
* [Ultima V](https://atariage.com/forums/topic/319655-ultima-v-world-explorer-in-antic-mode-e/page/2/?tab=comments#comment-4903483)
* [mad-pascal-playground](https://github.com/zbyti/mad-pascal-playground)
* [simple-games-easy-for-develop](https://github.com/zbyti/simple-games-easy-for-develop)
* [siege-ai-playground](https://github.com/zbyti/siege-ai-playground)
* [Cartfall](https://gitlab.com/bocianu/cartfall)
* [gravity](https://gitlab.com/bocianu/gravity)
* [Unicode](https://gitlab.com/amarok8bit/unicode)
* [Arcadia](https://gitlab.com/amarok8bit/arcadia)
* [atascii compo3](https://gitlab.com/bocianu/atasciicompo3)
* [ProHiBan](https://github.com/zbyti/ProHiBan)
* [The Hangmad](https://gitlab.com/bocianu/thehangmad)
* [Block Attack](https://github.com/tebe6502/Block-Attack)
* [Dungeon Adventurer](https://gitlab.com/delysio/dungeon-adventurer/)
* [neo Tetris](https://gitlab.com/bocianu/neo-tetris?fbclid=IwAR3EYa-u0ik7vTS156jJiRrqyyAJwq2Hl-xAYgrmCNtktC1Fvh3PZ2XLjXw)
* [µSoukoban](https://github.com/zbyti/pikoban)
* [Time Wizard](https://gitlab.com/amarok8bit/time-wizard)

## Benchmarks

|                             |CC65 |Mad Pascal|Millfork|
|:----------------------------|:----|:--------:|:------:|
|Sieve (less is better)       |602  |577       |579     |
|YoshPlus (higher is better)  |41933|41933     |41933   |
|Chessboard (higher is better)|76   |88        |82      |

[https://github.com/tebe6502/Mad-Pascal/blob/master/samples/benchmark.7z](https://github.com/tebe6502/Mad-Pascal/blob/master/samples/benchmark.7z)

### Floating Point

| iteration x 256             |Atari OS|FastChip|MP Single|MP Real|
|:----------------------------|:-------|:------:|:-------:|:-----:|
|add, sub, mul, div           | 232    | 118    | 64      | 99    |
|add, sub, mul, div, sin, cos | 5820   | 2915   | 3728    | 1231  |

* MP Single: IEEE754-32bit
* MP Real: Q24.8 Fixed Point

[https://github.com/tebe6502/Mad-Pascal/blob/master/samples/fp_benchmark.7z](https://github.com/tebe6502/Mad-Pascal/blob/master/samples/fp_benchmark.7z)

### Suite

![suite-animation](https://github.com/zbyti/a8-mad-pascal-bench-suite/raw/master/suite.gif)

[sources](https://github.com/zbyti/a8-mad-pascal-bench-suite)

## Links

* [HOME Page](http://mads.atari8.info/)
* [Mad Pascal on Atari Age Forum](https://atariage.com/forums/topic/240919-mad-pascal/)
* [Games in Mad Pascal](https://forums.atariage.com/topic/249968-games-in-mad-pascal/)
* [Mad Pascal examples](https://forums.atariage.com/topic/243658-mad-pascal-examples/)
* [Mad Pascal on Atari Area Forum](http://www.atari.org.pl/forum/viewtopic.php?id=13373)
* [Mad Pascal Announcement for WUDSN](https://atariage.com/forums/topic/145386-wudsn-ide-the-free-integrated-atari-8-bit-development-plugin-for-eclipse/?do=findComment&comment=4340150)
* [Some advice](https://github.com/ilmenit/CC65-Advanced-Optimizations)
* [Programowanie w Mad Pascal dla C+4](https://c64portal.pl/2021/02/22/programowanie-w-mad-pascal-dla-c4/)
* [Commodore Plus/4, Mad Pascal i bitmapy](https://c64portal.pl/2021/04/10/commodore-plus-4-mad-pascal-i-bitmapy/)

## YouTube

* [Arcadia](https://youtu.be/cJXRhfvKeH4)
* [Flob](https://youtu.be/sH4mg0DtWTM)
* [ProHiBan (Sokoban)](https://youtu.be/4VDKaIR_moY)
* [The Hangmad](https://youtu.be/6nkBs1NJUPU)
* [gravity](https://youtu.be/xCwlX6QSn80)
* [Block Attack](https://youtu.be/2LqFITTgDPI)
* [Turbo Pascal "Sokoban"](https://youtu.be/bsQsEM3TYTA)
* [Tron +4. Mad Pascal i C+4](https://youtu.be/a4Y2TYj1ymg)
* [Mad Pascal Commodore Plus/4 plasma effect with TEDzakker demo music](https://youtu.be/Yg10zHR--14)
* [Dungeon Adventurer](https://youtu.be/7lLPm5MywPc)

## Pascal compilers for the Atari XE/XL computer 

* [APX Atari Pascal](https://atariwiki.org/wiki/Wiki.jsp?page=APX%20Atari%20Pascal)
* [Kyan Pascal](https://atariwiki.org/wiki/Wiki.jsp?page=Kyan%20Pascal)
* [Draper Pascal](https://atariwiki.org/wiki/Wiki.jsp?page=Draper%20Pascal)
* [CLSN Pascal](https://atariwiki.org/wiki/attach/Pascal/CLSN_Pascal-Manual.pdf)

