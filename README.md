# 1120172188
北京理工大学软件工程大作业（个人）
Sudoku.cpp为程序主程序，Sudoku.h为头文件SodoMaker.cpp和SodoSolve.cpp为前期试验代码，不参与工程。

使用说明
生成数独终局
cmd命令行窗口中打开Sudoku.exe所在文件夹
在窗口中输入 "Sudoke.exe -c N" N为数目

解决数独残局
cmd命令行窗口中打开Sudoku.exe所在文件夹
在窗口中输入 "Sudoke.exe -c FILE_PATH" FILE_PATH为数独残局文件所在路径，最好为绝对路径。

仅需执行Sudoke.cpp和Sudoku.h即可生成可执行文件。
注：visual studio2017会出现预编译问题，解决方案是打开项目属性页，在C/C++选项中选择预处理器，并在右边的预处理器定义中加上 _CRT_SECURE_NO_WARNINGS （注意用分号隔开前面的定义）。

项目结构
|——README.MD
|——BIN
|   |——Sudoke.exe -可执行文件
|   |——sudoku.txt—程序执行生成的数独终局存放文件
|   |——questions.txt——数独残局1000个
|——Sudoku.cpp—主程序
|——Sudoke.h—主程序头文件
|——SodoMaker.cpp—早期代码，不在项目中使用
|——SudoSolve.cpp——早期代码，不在项目中使用
|——UnitTest.cpp—单元测试代码
