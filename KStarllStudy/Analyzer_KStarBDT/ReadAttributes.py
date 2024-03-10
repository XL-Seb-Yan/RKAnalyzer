## Need to run with python3

import ROOT
from DataFormats.FWLite import Handle, Events

# Set up pf handle and label
pfs = Handle("std::vector<pat::PackedCandidate>")
pfLabel = ("packedPFCandidates", "", "RECO")

# Event loop
events = Events('/eos/home-x/xuyan/RKProj/lowpt/RunF.root') # Replace 'file.root' with your file

for iev, event in enumerate(events):
    if iev > 0: break
    event.getByLabel(pfLabel, pfs)
    
    # Loop over pfs in the event
    for i, pf in enumerate(pfs.product()):
        if pf.pdgId() != 211: continue;
        print(pf.bestTrack())