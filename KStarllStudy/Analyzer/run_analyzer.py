import os
import sys
import time
file_list = [
"/eos/home-x/xuyan/RKProj/KStarllStudy/Data/K0StarEE/myNano_0.root",
"/eos/home-x/xuyan/RKProj/KStarllStudy/Data/K0StarEE/myNano_1.root",
"/eos/home-x/xuyan/RKProj/KStarllStudy/Data/K0StarEE/myNano_2.root",
"/eos/home-x/xuyan/RKProj/KStarllStudy/Data/K0StarEE/myNano_3.root",
"/eos/home-x/xuyan/RKProj/KStarllStudy/Data/K0StarEE/myNano_4.root"
        ]
        
for i, file in enumerate(file_list):
    path_parts = file.split('/')
    file_name = path_parts[-1]
    name_parts = file_name.split('_')
    index_number = int(name_parts[1].split('.')[0])
    
    # os.system("rm test.root")
    # os.mkdir(f"temp_{index_number}")
    # os.chdir(f"temp_{index_number}")
    # os.system("cp ../analyzer.C ./")
    # os.system(r"nohup root -l -q -b analyzer.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")
    # os.chdir("/eos/home-x/xuyan/RKProj/KStarllStudy/Analyzer")
    
    # os.chdir(f"temp_{index_number}")
    # os.system(f"mv outputHits_{index_number}.root ../")
    # os.chdir("../")
# os.system("hadd test.root outputHits_*.root")
# os.system("rm -r temp* outputHits_*.root")

    print("nohup root -l -q -b analyzer.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")