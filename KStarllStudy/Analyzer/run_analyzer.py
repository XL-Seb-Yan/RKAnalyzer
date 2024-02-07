import os
import sys
import time


# file_list = [
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_0.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_1.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_10.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_11.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_12.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_13.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_14.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_15.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_16.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_17.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_18.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_19.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_2.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_20.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_3.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_4.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_5.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_6.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_7.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_8.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_9.root",
        # ]
        
file_list = [
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE/myNano_1.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE/myNano_2.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE/myNano_3.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_1.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_10.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_11.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_12.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_13.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_14.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_15.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_16.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_17.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_18.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_19.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_2.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_20.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_21.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_22.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_23.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_24.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_25.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_26.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_27.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_28.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_29.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_3.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_30.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_31.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_32.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_33.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_34.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_35.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_4.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_5.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_6.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_7.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_8.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_postEE_ext1/myNano_9.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_1.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_10.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_2.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_3.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_4.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_5.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_6.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_7.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_8.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE_ext1/myNano_9.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BdToK0starEE_preEE/myNano_1.root",
        ]
        
        
        
for i, file in enumerate(file_list):
    path_parts = file.split('/')
    file_name = path_parts[-1]
    name_parts = file_name.split('_')
    index_number = int(name_parts[1].split('.')[0])
    sample_name = path_parts[-2]
    
    
    # os.mkdir(f"temp_{sample_name}_{index_number}")
    # os.chdir(f"temp_{sample_name}_{index_number}")
    # if sample_name == "BuToKEE":
        # print("BuToKEE")
        # os.system("cp ../analyzer_MC_131_triplets.C ./")
        # os.system(r"nohup root -l -q -b analyzer_MC_131_triplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(0) + "\) &")
    # elif "BdToK0starEE" in sample_name:
        # os.system("cp ../analyzer_MC_131_quadruplets.C ./")
        # os.system(r"nohup root -l -q -b analyzer_MC_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")
    
    # os.chdir("/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Analyzer")
    
    os.chdir(f"temp_{sample_name}_{index_number}")
    os.system(f"mv outputHits_{index_number}.root ../")
    os.system(f"mv outputTree_{index_number}.root ../")
    os.chdir("../")
os.system("hadd Hist.root outputHits_*.root")
os.system("hadd Tree.root outputTree_*.root")
os.system("rm -r output*.root")
os.system("rm -r temp* output*.root")

# os.system(r"nohup root -l -q -b analyzer_Data.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")
# print(r"nohup root -l -q -b analyzer_MC_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")

    