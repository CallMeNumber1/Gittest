## `which` 
- `type`



文件类型
7种类型

## 普通文件又可以分为三种：
	纯文本文件
	二进制文件(不能用cat读取）
	数据文件(只能用特定软件读出）
## 文件权限rwx
权限包括三组：用户 用户组 其他用户
与文件权限有关的命令
chmod
chmod a+x file
chmod o-x file
chmod 755 file
chown修改文件所属的用户
chown suyelu:haizei file
chown -R wuyelu:haizei directory
chown suyelu file
chgrp修改文件所属的组
chgrp root file
- sudo 临时获取管理员权限
- su 切换用户
- sudo -i切换到root

## shell terminal console

#### man
-f
-k 

## bash
- 通配符 ？单个字符 ×任意多个字符
[list]匹配list其中一个字符
[!list]匹配除list外的所有字符
[0-9][a-z]
{string1},string}匹配字符串
### 任务管理
- command & 后台执行
- command;command 顺序执行
- command && command 第一个成功执行第二个才执行
- command || command
- ``命令中包含另一个命令时，用符号包括起来
- 结束进程
	可用pkill ping根据进程名字杀死进程
	或者用kill + pid
### 管道 重定向
- >> 追加
- << ?
### 转义符

### shell元字符
- =
- ``取命令的执行结果
- $变量值替换 $[]整数计算
- | 管道命令 先进先出，出去就消失了
- !+序号可以执行history里面的指令
- ctl + r 可以检索历史命令
- .当前目录
- -上次工作目录
- -根目录

### 目录结构
- /mnt来挂载优盘

### 配置文件
- /etc/fstab 查看文件系统
- 用户系统
	/etc/passwd
	/etc/group
- shell
	/etc/profile 用户首选项
	/etc/bashrc bash配置文件
- 系统环境（所有用户通用）
	/etc/issue 发行信息
- 网络 （所有用户通用）
	/etc/hostname 主机名
	/etc/hosts 主机列表
- 环境变量
	env
- 常见环境变量（可通过man手册查看）
~/.bashrc
~/.bash_profile
~.bash_logout
bash.bashsrc

#### date 查看当前时间
date +"%..." 以什么格式输出

