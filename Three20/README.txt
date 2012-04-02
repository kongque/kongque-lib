中文说明：

将Three20的代码直接添加到工程中，如果要正常运行，还需要如下两个步骤：

1）在工程的设置中Build Settings设置头文件搜索路径，将Three20所在的目录添加到头文件搜索路径中。

2) 在工程的设置的Build Phases标签页，添加Link Binary With Libraries添加QuartzCore.framework，否则会有链接错误。

经过以上步骤，源码添加Three20就可以正常使用了。

=====================================================================

English:

Add Three20 source code to your project for usage, you still need two step finish it.

1) Project Settings -> Build Settings tab -> Search Paths -> Header Search Paths 
   Add Three20 directory as a Header Search Paths Item.

2) Project Settings -> Build Phases tab -> Link Binary With Libraries. Add QuartzCore.framework to you project. otherwise you will get a link error.

Enjoy it!


