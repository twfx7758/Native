/*
							Vs2012建立引用lib、dll简明教程  
一、 基本概念  Lib——静态链接库 用到的指令都被直接包含在exe文件中，程序运行的时候不再需要其它的库文件。
	静态共享代码  DLL——把调用的函数所在dll和函数所在位置信息链接至程序中，程序运行的时候再从DLL中寻找相应函数代码，
	因此需要相应DLL文件的支持。动态引用和卸载   
二、 vs2012建立和引用lib 
建立lib  
1. 创建静态项  选择win32控制台应用程序->输入项目名称->选择静态链接库->取消 默认预编译头->完毕。  
2. 编写库  创建cpp和h文件，并编写内容。 
3. 编译，创建完成，新lib在输出路径（debug）中。
 
引用lib 
1. 创建工程 略 
2. 编写程序 略  
3. 在项目->属性->配置属性->vc++目录->包含目标中附加之前工程的头文件的目录 
4. 在引用->通用属性->框架和引用->添加引用->勾选相应目录->确定（lib项目和该项目在同一路径下时）。  或者在vc++目录->库目录中添加新lib的路径，在链接器->输入->附加依赖项中添加新lib。  
5. 完成。在编写程序时要加上头文件包含。

三、 vs2012建立和引用dll 
建立dll  
1.创建动态项 选择win32控制台应用程序->输入项目名称->选择动态链接库->取消默认预编译头->完毕。 
2.编写库  创建cpp和h文件，并编写内容。在h文件中对函数的声明时注意，
  对于该dll输出接口的函数要用__declspec(dllexport)声明，
  如 extern “C”int Add(int &a,int &b);   
  加extern“C”是为了解决因C编译器与C++编译器对函数声明的编译情况不同（c语言不支持重载），而导致的调用错误。
  如果已知在c++环境下调用，可不必加。 
3.引用dll同时需要lib文件，再在项目中添加一个def文件。 
4.编译生成，新dll和lib在输出路径（debug）中。  此处的lib存放的是dll的函数入口位置，与单纯静态链接库 lib不同。 

引用dll 
1.创建工程 略 
2.编写程序 略  
3.在项目->属性->配置属性->vc++目录->包含目标中附加dll的头文件的目录 
4.在引用->通用属性->框架和引用->添加引用->勾选相应目录->确定（dll项目和该项目在同一路径下时）  或者在vc++目录->库目录中添加新lib的路径，在链接器->输入->附加依赖项中添加新lib。  
5.完成。在编写程序时要加上头文件包含。
*/