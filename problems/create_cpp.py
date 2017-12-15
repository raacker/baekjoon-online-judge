import os

dir_list = open('./dir_list', 'r')

for dir_name in dir_list:
    os.system("touch ./"+ dir_name[0:-2] + "/"+ dir_name[0:-2] + ".cpp")
