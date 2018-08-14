#bin/bash
x='~/home/chongh/mygit'
echo "welcome chongh!"     #测试登录时能否自动执行
for file in "/home/chongh"; do
	if [[ -f file ]]; then
	    chown chongh $file		
	fi	
done
