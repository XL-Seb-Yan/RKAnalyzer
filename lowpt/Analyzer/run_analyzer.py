import os
import sys
import time
file_list = [
        "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_0.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_1.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_10.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_11.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_12.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_13.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_14.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_15.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_16.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_17.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_18.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_19.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_2.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_20.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_21.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_22.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_23.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_24.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_25.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_26.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_27.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_28.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_29.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_3.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_30.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_31.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_32.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_33.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_34.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_35.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_36.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_37.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_38.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_39.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_4.root",
"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_40.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_41.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_42.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_43.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_44.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_45.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_46.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_47.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_48.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_49.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_5.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_50.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_6.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_7.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_8.root",
# "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_9.root",
        ]
        
for i, file in enumerate(file_list):
    path_parts = file.split('/')
    file_name = path_parts[-1]
    name_parts = file_name.split('_')
    index_number = int(name_parts[1].split('.')[0])
    
    # os.system(f"rm test.root")
    # os.mkdir(f"temp_{index_number}")
    # os.chdir(f"temp_{index_number}")
    # os.system("cp ../analyzer.C ./")
    # os.system(r"nohup root -l -q -b analyzer.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")
    # os.chdir("/eos/home-x/xuyan/RKProj/lowpt/Analyzer")
    
    os.chdir(f"temp_{index_number}")
    os.system(f"mv outputHits_allID_{index_number}.root /eos/home-x/xuyan/RKProj/lowpt/Analyzer/")
    os.chdir("/eos/home-x/xuyan/RKProj/lowpt/Analyzer")
os.system(f"hadd test.root outputHits_allID_*.root")
os.system(f"rm -r temp* outputHits_allID_*.root")