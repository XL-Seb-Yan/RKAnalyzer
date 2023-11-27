import os
import sys
import time
file_list = [
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_1.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_10.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_11.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_12.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_13.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_14.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_15.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_16.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_17.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_18.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_19.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_2.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_20.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_21.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_22.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_23.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_24.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_25.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_26.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_27.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_28.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_29.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_3.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_30.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_31.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_32.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_33.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_4.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_5.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_6.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_7.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_8.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_9.root"
        ]
        
# file_list = [
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/K0StarEE/myNano_0.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/K0StarEE/myNano_1.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/K0StarEE/myNano_2.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/K0StarEE/myNano_3.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/K0StarEE/myNano_4.root"
        # ]
        
for i, file in enumerate(file_list):
    path_parts = file.split('/')
    file_name = path_parts[-1]
    name_parts = file_name.split('_')
    index_number = int(name_parts[1].split('.')[0])
    
    # os.system("rm test.root")
    # os.mkdir(f"temp_{index_number}")
    # os.chdir(f"temp_{index_number}")
    # os.system("cp ../analyzer_MC.C ./")
    # os.system(r"nohup root -l -q -b analyzer_MC.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(0) + "\) &")
    # os.chdir("/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Analyzer")
    
    os.chdir(f"temp_{index_number}")
    os.system(f"mv outputHits_{index_number}.root ../")
    os.chdir("../")
os.system("hadd test.root outputHits_*.root")
os.system("rm -r temp* outputHits_*.root")

    # print("nohup root -l -q -b analyzer.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")