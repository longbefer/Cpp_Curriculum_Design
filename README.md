--------CN--------------

这是c++课程设计的一部分
2.1 系统功能分析：
系统通过调用函数来实现字符的输入与输出，GameTwo、GameOne通过调用CharTrain类的RandomWords()来随机生成文本，通过调用JudgeWords()用于字符的判断，通过调用EarseWords()来擦除错误地方文本；GameThree通过调用LocalText类的ShowText()函数来读取文件中的字符串，调用JudgeWord()来判断输入的字符是否正确，通过调用计时器类来得到游戏时间总长，而主函数main()用于调用这些函数。 
2.2系统功能模块划分与设计：
系统主要定义了LocalText类、CharTrain类、CountTime类、Tools类等类，定义了RandomWords()，JudgeWords()，EarsrWords()等函数来实现支持英文的游戏，定义了ShowText(),JudgeWord()来支持本地中文的读取、输入判断操作，CountTime类通过调用系统时间来定义游戏时间，GameOne、GameTwo、GameThree类通过调用各自所需的类来完成游戏所需功能。

其中，在运行exe文件时，请把LocalText.txt文件添加在exe文件旁边

---------EN-------------

This is my C Plus plus curriculum design.
Character input and output are realized by calling functions in the system,GameTwo and GameOne generate text randomly by calling RandomWords () of CharTrain class, erase the wrong local text by calling EarseWords () for character judgment, and GameThree reads strings in files by calling ShowText () function of LocalText class, and calls JudgeWord () to determine whether the input characters are correct or not, and by calling timer class. To get the total game time, the main () function is used to call these functions.
The system mainly defines the classes of LocalText, CharTrain, CountTime and Tools, defines RandomWords (), JudgeWords (), EarsrWords () and other functions to implement English-supported games, defines ShowText (), JudgeWord () to support local Chinese reading, input and judgment operations, and CountTime class defines game time by calling system time, GameOne, GameTwo, GameTheThree class completes the required functions of the game by calling the required classes.

!!!important!!!
When running the EXE file, add the LocalText.txt file next to the EXE file
