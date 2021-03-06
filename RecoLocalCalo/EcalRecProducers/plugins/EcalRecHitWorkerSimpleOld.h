#ifndef RecoLocalCalo_EcalRecProducers_EcalRecHitWorkerSimpleOld_hh
#define RecoLocalCalo_EcalRecProducers_EcalRecHitWorkerSimpleOld_hh

/** \class EcalRecHitSimpleAlgo
  *  Simple algoritm to make rechits from uncalibrated rechits
  *
  *  \author Shahram Rahatlou, University of Rome & INFN, March 2006
  */

#include "RecoLocalCalo/EcalRecProducers/interface/EcalRecHitWorkerBaseClass.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalRecHitSimpleAlgo.h"

#include "FWCore/Framework/interface/ESHandle.h"

#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalTimeCalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalTimeOffsetConstant.h"
#include "CondFormats/EcalObjects/interface/EcalADCToGeVConstant.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"

#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbService.h"

class EcalRecHitWorkerSimpleOld : public EcalRecHitWorkerBaseClass {
        public:
                EcalRecHitWorkerSimpleOld(const edm::ParameterSet&, edm::ConsumesCollector& c);
				EcalRecHitWorkerSimpleOld(const edm::ParameterSet&);
                virtual ~EcalRecHitWorkerSimpleOld();                       
        
                void set(const edm::EventSetup& es);
                bool run(const edm::Event& evt, const EcalUncalibratedRecHit& uncalibRH, EcalRecHitCollection & result);



        protected:

		double EBLaserMIN_;
		double EELaserMIN_;
		double EBLaserMAX_;
		double EELaserMAX_;


                edm::ESHandle<EcalIntercalibConstants> ical;
                edm::ESHandle<EcalTimeCalibConstants> itime;
                edm::ESHandle<EcalTimeOffsetConstant> offtime;
                edm::ESHandle<EcalADCToGeVConstant> agc;
                edm::ESHandle<EcalChannelStatus> chStatus;
                std::vector<int> v_chstatus_;
                edm::ESHandle<EcalLaserDbService> laser;

		std::vector<int> v_DB_reco_flags_;

                bool killDeadChannels_;
                bool laserCorrection_;

                EcalRecHitSimpleAlgo * rechitMaker_;
};

#endif
