#include "DQMOffline/PFTau/plugins/CandidateBenchmarkAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"


using namespace reco;
using namespace edm;
using namespace std;



CandidateBenchmarkAnalyzer::CandidateBenchmarkAnalyzer(const edm::ParameterSet& parameterSet) : 
  BenchmarkAnalyzer(parameterSet),
  CandidateBenchmark( (Benchmark::Mode) parameterSet.getParameter<int>("mode") )
{

  setRange( parameterSet.getParameter<double>("ptMin"),
	    parameterSet.getParameter<double>("ptMax"),
	    parameterSet.getParameter<double>("etaMin"),
	    parameterSet.getParameter<double>("etaMax"),
	    parameterSet.getParameter<double>("phiMin"),
	    parameterSet.getParameter<double>("phiMax") );

  myColl_ = consumes< View<Candidate> >(inputLabel_);
}


void 
CandidateBenchmarkAnalyzer::beginJob()
{

  BenchmarkAnalyzer::beginJob();
  setup();
}

void 
CandidateBenchmarkAnalyzer::analyze(const edm::Event& iEvent, 
				      const edm::EventSetup& iSetup) {
  
  
  Handle< View<Candidate> > collection; 
  //iEvent.getByLabel( inputLabel_, collection); 
  iEvent.getByToken(myColl_, collection);

  fill( *collection );
}


void CandidateBenchmarkAnalyzer::endJob() {
}
