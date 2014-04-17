import FWCore.ParameterSet.Config as cms
trackTriggerStudy = cms.EDAnalyzer("TrackTriggerStudy",
                                   mcType = cms.uint32(1),
                                   egammaSrc = cms.InputTag("SLHCL1ExtraParticles","EGamma"),
                                   DebugFlag            = cms.bool(False),
                                   EGammaETThreshold    = cms.double(2.0),
                                   GeometryOption       = cms.string("LB_6PS"),
                                   StubPtCut            = cms.double(3.0), 
                                   TrackEGammadPhiCut   = cms.double(0.08),
                                   TrackEGammadRCut     = cms.vdouble(0.05, 0.1, 0.15),
                                   TrackEGammaEtoPCut   = cms.vdouble(0.5, 2.5), 
                                   StubEGammadPhiCut    = cms.double(0.1),
                                   StubEGammadZCut      = cms.double(35.0),
                                   StubEGammaPhiMissCut = cms.double(0.1),
                                   StubEGammaZMissCut   = cms.double(2.0),
                                   LongBarrelRadii = cms.vdouble(0.0,36.0,40.0,54.0,58.0,69.5,73.5,83.5,87.5,96.5,100.5),  
                                   BarrelEndCapRadii = cms.vdouble(0.0,22.73,35.56,50.62,68.40,88.59,107.8),
                                   BarrelEndCap5DRadii = cms.vdouble(0.0, 22.59, 35.48, 50.54, 68.31, 88.5, 107.71), 
                                   EndCapDiscPositions  = cms.vdouble(0.0, 0.0, 0.0, 0.0, 0.0,0.0, 0.0)
                                    
)                                   
