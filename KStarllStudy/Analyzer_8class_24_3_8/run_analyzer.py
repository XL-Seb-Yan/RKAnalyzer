import os
import sys
import time
import subprocess

file_list = []
if sys.argv[2] == "KEE":
    file_list = [
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_0.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_1.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_10.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_11.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_12.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_13.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_14.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_15.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_16.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_17.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_18.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_19.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_2.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_20.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_3.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_4.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_5.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_6.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_7.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_8.root",
    "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/BuToKEE/myNano_9.root",
            ]
elif sys.argv[2] == "KsEE":
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

elif "DataF" in sys.argv[2]:
    file_list = [
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_0.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_1.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_10.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_100.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_101.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_102.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_103.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_104.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_106.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_107.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_108.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_109.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_11.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_110.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_111.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_112.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_113.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_114.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_115.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_116.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_117.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_118.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_119.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_12.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_120.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_121.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_122.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_123.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_124.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_125.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_126.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_127.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_13.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_130.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_131.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_132.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_133.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_134.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_135.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_136.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_137.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_138.root",
"/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_139.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_14.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_140.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_141.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_142.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_143.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_144.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_145.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_146.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_147.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_148.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_149.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_15.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_150.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_156.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_157.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_158.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_16.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_160.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_162.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_163.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_164.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_165.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_166.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_167.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_168.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_169.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_17.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_170.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_171.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_172.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_173.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_174.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_175.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_176.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_177.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_178.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_179.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_18.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_180.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_181.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_182.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_183.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_184.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_185.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_186.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_187.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_188.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_189.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_19.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_190.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_191.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_192.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_193.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_194.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_195.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_196.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_197.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_198.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_199.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_2.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_20.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_200.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_21.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_22.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_23.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_24.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_25.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_26.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_28.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_29.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_3.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_30.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_33.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_34.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_35.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_36.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_37.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_38.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_39.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_4.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_40.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_41.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_42.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_43.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_44.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_45.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_46.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_47.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_48.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_49.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_5.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_50.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_51.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_52.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_53.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_54.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_55.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_56.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_57.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_58.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_59.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_6.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_60.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_61.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_62.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_63.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_64.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_65.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_66.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_67.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_68.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_69.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_7.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_70.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_71.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_74.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_75.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_76.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_78.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_79.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_8.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_80.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_81.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_82.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_83.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_84.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_85.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_86.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_87.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_88.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_89.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_9.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_90.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_91.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_92.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_93.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_94.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_95.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_96.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_97.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_98.root",
# "/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646/myNano_99.root",
]

            
os.system("rm -r Hist.root Tree.root")
        
        
if sys.argv[1] == "produce":
    for i, file in enumerate(file_list):
        path_parts = file.split('/')
        file_name = path_parts[-1]
        name_parts = file_name.split('_')
        index_number = int(name_parts[1].split('.')[0])
        sample_name = path_parts[-2]
          
        os.mkdir(f"temp_{sample_name}_{index_number}")
        os.chdir(f"temp_{sample_name}_{index_number}")
        if "BdToK0starEE" in sample_name:
            print(sample_name)
            os.system("cp ../analyzer_MC_131_triplets.C ./")
            os.system("cp ../analyzer_MC_131_triplets.C ./")
            os.system(r"nohup root -l -q -b analyzer_MC_131_triplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")
            # print(r"nohup root -l -q -b analyzer_MC_131_triplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(0) + "\) &")
        elif sample_name == "BuToKEE":
            os.system("cp ../analyzer_MC_131_quadruplets.C ./")
            # print(r"nohup root -l -q -b analyzer_MC_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")
            os.system(r"nohup root -l -q -b analyzer_MC_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(0) + "\) &")
        elif "DataF" in sample_name and "tri" in sys.argv[2]: 
            print("Data")
            os.system("cp ../analyzer_Data_131_triplets.C ./")
            os.system("cp ../analyzer_Data_131_triplets.C ./")
            os.system(r"nohup root -l -q -b analyzer_Data_131_triplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")
        elif "DataF" in sample_name and "quad" in sys.argv[2]:
            print("Data")
            os.system("cp ../analyzer_Data_131_quadruplets.C ./")
            # print(r"nohup root -l -q -b analyzer_Data_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")
            os.system(r"nohup root -l -q -b analyzer_Data_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(0) + "\) &")
        
        os.chdir("/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Analyzer")
    while True:
    # Execute the `ps -aux` command
        result = subprocess.run(['ps', 'aux'], stdout=subprocess.PIPE, text=True)
        print(result.stdout)
        time.sleep(20)
else:
    for i, file in enumerate(file_list):
        path_parts = file.split('/')
        file_name = path_parts[-1]
        name_parts = file_name.split('_')
        index_number = int(name_parts[1].split('.')[0])
        sample_name = path_parts[-2]

        os.chdir(f"temp_{sample_name}_{index_number}")
        os.system(f"cp outputHits_{index_number}.root ../outputHits_{sample_name}_{index_number}.root")
        os.system(f"cp outputTree_{index_number}.root ../outputTree_{sample_name}_{index_number}.root")
        os.chdir("../")
    os.system("hadd Hist.root outputHits_*.root")
    os.system("hadd Tree.root outputTree_*.root")
    os.system("rm -r temp* output*.root")

# os.system(r"nohup root -l -q -b analyzer_Data.C\(\"" + file + r"\"," + str(int(index_number)) + "\) &")
# print(r"nohup root -l -q -b analyzer_MC_131_quadruplets.C\(\"" + file + r"\"," + str(int(index_number)) + "," + str(10) + "\) &")

    