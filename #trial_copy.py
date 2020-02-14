#trial_copy.py
import os
import time
source=['"C:\\Users\\94718\\Documents\\cpp_study"']
target_dir=r'C:\\Users\\94718\Documents\\代码总览\\cpp_study'
target=target_dir+os.sep+'.zip'
if not os.path.exists(target_dir):
    os.mkdir(target_dir)
zip_command='zip -r {0} {1}'.format(target,' '.join(source))

print("zip command is:")
print(zip_command)
print("Running")
if os.system(zip_command)==0:
    print('Successful backup to',target)
else:
    print('Backup FAILED')
    pass