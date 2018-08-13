软件安装

- 源 ubantu官方的copy
  apt-get update
  apt-get upgrade
  sudo !! 在上一条命令前加上管理员权限
  apt-get install + name
  apt-cache search + name：检索包含name的软件
  dpkg -i：输出错误信息
  cd etc/apt/ -> ls：其中source.list是源，带.d后缀的是目录

简单命令

- cd
  -回到上次工作的目录
  ../上层目录
  $HOME家目录
  不加选项，默认回到家目录 
- ls：列出所有文件
  -a：列出包括隐藏文件
  .是当前目录，..是父目录
  -l：长列表形式
  ll：是个别名（简称）
  	`alias` 可以查看存在的别名
- cp
  可以将多个文件拷贝到一个目录中
- touch 创建空白文件
- mkdir 创建目录
- echo输出
  也可以打印变量
  变量赋值时：HOME=/ 中间不能加空格，且赋值仅终端内有效
- cat强制读出文件的内容
- pwd打印当前目录
- rm一定要注意当前目录
  -r递归
  -f强制
  /目录树上也删除
- mv
- man
- tldr
  python3 pip
  | 管道：将前面的标准输出作为标准输入给后面
  grep + "name"检索文本信息name
  	例如：apt-cache search pip | grep "python3"| grep pip
  安装python3-pip：sudo apt-get install python3-pip
  利用pip安装tldr：pip3 install name
  卸载：unistall
- 进入树莓派：ssh ChongH@192.168.1.40 
  密码:haizei

免密登录

oepnssh-client用来实现本地登录远程，openssh-server用来实现本地被远程访问。本地自带client，需要安装server(否则访问时会出现port22: Conneciton refused)，当两者版本不一致时会报依赖错误。只需重新安装client的对应版本即可。

- 本地免密登录远程
  执行命令ssh-keygen生成公钥，按回车，默认存到ssh/id_rsa.pub中，用户根目录会出现.ssh目录，在.ssh目录下执行命令cat id_rsa.pub，将打印出的公钥强制复制。
  然后登录远程，进入.ssh目录，如果没有authorized_keys文件，则新建此文件并授予权限600，chmod 600 ~/.ssh/autorized_keys，然后此文件，将公钥复制在里面即可。
- 本地免密被远程登录

Github

- 访问网站css不正确加载解决方案:
  sudo vim /etc/hosts在后面添加几行内容。
  详见https://blog.csdn.net/qq_36589706/article/details/80573008
- 添加ssh
- 安装GIt
- 配置用户名与邮箱（本地的，只需知道是谁做的）
  git config --global user.name ""
  user.email ""

基本使用

- 克隆仓库到本地
  git clone + "仓库名"
- git status查看工作区状态（是否有未提交的）
- git add(将新建的文件添加到提交队列)
  git add *
  git add .
  git reset HEAD 路径名/文件名 撤销添加
- git commit -m "info"（提交修改并且添加说明信息）
  git commit -a可以结合add
- git push将更改push到github
- git pull将本地与远程同步
- git log查看版本信息
  git reset --hard HEAD^回退到上一个版本
  HEAD^^  $HEAD^{100}$
  git reflog查看所有操作的提交id
  git reset --hard "id"回到对应状态。（id只需写前7位，其他的git版本库会自动匹配）
- 如何写一个脚本每天做这些事情

本地仓库项目push到Github远程仓库

- 首先在本地新建一个仓库，一般是要push哪个工程，就在那个工程目录下新建仓库。
  cd 工程目录 git init
  初始化后，工程当前目录下会出现一个名为.git的目录，该目录会记录和存放所有Git需要的数据和资源。
- 目前新的仓库还是空的，要注意的是只有仓库所在目录或者其子目录下的文件可添加至仓库中，其他目录下的文件Git无法找到
  git add . git commit -m ""
- 在本地仓库push到远程仓库之前，要关联本地仓库和远程仓库
  git remote add origin git@github.com:yourName/yourRepo.git
  命令执行后，origin即为远程仓库的名字
- 将本地仓库的文件push到远程仓库
  git push -u origin master
  注意：第一次推送master分支（Git默认分支），最好加上-u参数。该参数会将本地的master分支和远程的master分支关联起来，之后本地仓库和远程仓库之间的推送和拉取就可以简化为 git push git pull
- 注意:当push后报错：更新被拒绝，当前分支的最新提交落后于对应的远程分支。
  则可以用git push origin master合并。

分支操作

- git branch 分支名创建分支，创建时需要是最新的环境，依然停留在当前分支。
- git checkout
  git checkout 分支名切换分支
  git checkout 文件名放弃单个文件的修改
  git checkout .放弃当前目录的修改
- git branch -d dev删除dev分支（-D为强制删除）
- git merge合并分支

100台机器每两台之间互相免密访问

scp

SHELL编程

#!/bin/bash 用bash语法写的

- 执行脚本 bash + filename
  chmod(change mode改变权限) a+x  +filename
  执行时直接./filename.sh
  权限顺序：用户->用户组->其他人
- 变量与局部变量
  赋值号两边不许有空格
  弱类型语言
  ``命令替换符
  	`pwd` 代替命令的输出
  a = $a:a字符串拼接，$后面跟变量名
- 位置变量
  $0：当前执行shell脚本的文件名，包括路径
  $n：获取当前执行脚本的第n个参数
  $*：输出一个整体字符串
  $# 当前执行脚本的参数个数	
  $@ 获取这个程序的所有参数，并保留参数之间的任何空白，输出各个独立部分，与*相对应
- 状态变量
  $?：判断上一个指令是否成功执行，0为成功。
- 变量，参数展开
  ${a}：{}可以限定变量的作用范围。
  ${!prefix*}：匹配prefix开头的所有变量
  Linux下两个垃圾桶：/dev/zero /dev/null
- 输入输出
  read  [ -options ][variable]
  echo string
  	-e 开启转义
  	-n 不输出回车
  printf format-string [arguments]
- 函数
  三种定义方式：
      function _printf_() {
          echo $1
          return
      }
      _printf_() {
      	echo $1
      	return
      }
- 流程控制
  condition两端必须有空格
      #if
      if [[ condition ]]; then
      
      fi
      #表达式两端要有空格
      ##如果是数值类型的数据，使用let(())进行判断，对于字符串等使用test[[]]进行判断。(())中变量可以不用$来引用。
      
      #case 
      case word in
      	pattern )
      		;;
      esac
      
      #while
      while [[ condition ]]; in
      	
      	
      #until
      
      #for
      for i in 'seq 1 100'; do  #生成1～100的数字序列
      	#staements
      done
      
      for (( i = 0; i < 10; i++)); do
      	#statements
      done
  
- 数组
  数组的声明：declare -a array
  输出数组内容：${array[*]} ${array[@]}
  取数组长度：${#array[*]}
  数组的访问：${array[ind]}	
  数组追加：array+=(1 2 3)
  删除数组元素：unset
  数组排序：sort
      #生成1到100的一个数组
      a=('seq 1 100')
      #当不加括号时，生成的是一个从1到100连起来的字符串
      a='seq 1 100'
- 运算符
      #算术表达式赋值
      可以写在(())中，且不用加 $ 符号
      也可以：a=1 b=$[$a+1] 写在中括号里
      #整数比较运算符（浮点型数值不能使用）
      -eq -gt -lt -ge -le -ne
      #字符串运算符
      = != -n（判断是否不为空） -z（是否为空）
      #逻辑运算符
      ! -a -o 
      #算术运算符（可以与=连用，称为算术复合运算符）
      #使用let命令来执行算术运算，使用算术运算符无法对字符串、文件、浮点型进行计算（浮点型操作，需要用到专门的函数）
      let "a=5+{++num}"
      #自增运算符
      #数字常量
      #bc运算器，使用其进行浮点数运算需要使用命令替换的方式。
      #bc运算器定义了内建变量scale用于设定除法运算的精度（默认为0）
      var1=20
      var2=3.14159
      var3=`echo "scale=5; $var1^2 | bc"`
      var4=`echo "scale=5; $var3*$var2" | bc`
      
- Linux中挂起(ctrl+z)，然后输入fg即可回去，若挂起多个，可以用jobs查看，并用fg+数字回去
- 获取单个文件大小ls -l filename | awk '{print $5}'
- 显示当前目录下的文件（夹）ls dirname
- mkdir -p 可以是一个路径名称。此时若路径中的某些目录尚不存在,加上此选项后,系统将自动建立好那些尚不存在的目录,即一次可以建立多个目录
- rm
  -r 递归删除目录及其子目录
  -f 当文件为空时不输出错误信息
  -rf 

定时任务

- find命令find pathname -options [-exec]
  pathname 是find命令所查找的目录路径
  -exec 对匹配的文件执行该参数所给出的shell命令
  -options 选项参数
  	-name 按照文件名查找文件
  	-mtime -n +n 按照文件的更改时间来查找文件，+n表示n天前
  	-type 查找某一类型的文件
  找两种类型的文件 -type f -o -type d
- crontab
  格式：分钟 小时 日 月 星期 命令
  参数:
  -e [UserName]: 执行文字编辑器来设定时程表，内定的文字编辑器是 VI，如果你想用别的文字编辑器，则请先设定 VISUAL 环境变数来指定使用那个文字编辑器(比如说 setenv VISUAL joe)
  -r [UserName]: 删除目前的时程表
  -l [UserName]: 列出目前的时程表
  -v [UserName]:列出用户cron作业的状态	

作业一

- 查找一个目录下所有文件中最长的字符串
  ~/task.sh

作业二

- 垃圾箱
