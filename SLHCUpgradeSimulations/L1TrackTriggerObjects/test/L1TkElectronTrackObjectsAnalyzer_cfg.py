import FWCore.ParameterSet.Config as cms

process = cms.Process("test")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
    'file:L1TrackElectron.root'
    #'file:example_withEtMiss.root'
    #'file:example_w_Tracks.root'
    )
)




process.ana = cms.EDAnalyzer( 'L1TkElectronTrackObjectsAnalyzer' ,
    L1TkElectronsInputTag = cms.InputTag("L1TkElectrons","EG"),
    L1EGammaInputTag = cms.InputTag("SLHCL1ExtraParticles","EGamma"),
    AnalysisOption   = cms.string("Efficiency")                              
)


# root file with histograms produced by the analyzer
filename = "ana.root"
process.TFileService = cms.Service("TFileService", fileName = cms.string(filename), closeFileFast = cms.untracked.bool(True)
)

process.p = cms.Path( process.ana )




