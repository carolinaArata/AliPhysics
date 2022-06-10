/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. */
/* See cxx source for full Copyright notice */
/* Add a description of your MPI analysis */

#ifndef AliAnalysisTaskFlatenicityPiKp_H
#define AliAnalysisTaskFlatenicityPiKp_H

class AliESDtrackCuts;
class AliESDEvent;
class TList;
class TH1D;
class TH2D;
class TH3D;
class TH3F;
class TH1I;
class TF1;
class TProfile;
class THnSparse;

#include "AliAnalysisTaskSE.h"

#include "AliGenEventHeader.h"
#include "AliMCEvent.h"
#include "AliMCEventHandler.h"
#include "AliMCParticle.h"
#include "AliStack.h"
#include "TParticle.h"

class AliAnalysisTaskFlatenicityPiKp : public AliAnalysisTaskSE {
	public:
		AliAnalysisTaskFlatenicityPiKp();
		AliAnalysisTaskFlatenicityPiKp(const char *name);
		virtual ~AliAnalysisTaskFlatenicityPiKp();

		virtual void UserCreateOutputObjects();
		virtual void UserExec(Option_t *option);
		virtual void Terminate(Option_t *option);
		Double_t GetFlatenicityV0();
		Double_t GetFlatenicityTPC();
		Double_t GetFlatenicityMC();
		void MakeMCanalysis();
		void MakeMCanalysisPID();
		void ElectronsContamination();
		void MakeDataanalysis();
		void MakePIDanalysis();

		void SetPtMin(Double_t val) { fPtMin = val; } // Set pT cut for associated particles
		void SetNcl(UShort_t ncl) { fNcl = ncl; } // Set pT cut for associated particles
		void SetUseMC(Bool_t flat_flag = kFALSE) { fUseMC = flat_flag; } // use to analyse MC data
		void IsdEdxCalibrated(Bool_t dEdxCal = kTRUE) { fdEdxCalibrated = dEdxCal; }
		void SetV0MBin(TString v0mbin = "0_1") { fV0MBin = v0mbin; }
		void SetDetectorForFlatenicity(TString det = "V0") { fDetFlat = det; }
		void SetDataPeriod(TString period = "16l") { fPeriod = period;}
		void SetMCclosureTest(Bool_t flat_flag = kFALSE) { fIsMCclosure = flat_flag; }
		void SetRemoveTrivialScaling(Bool_t flat_flag = kFALSE) {
			fRemoveTrivialScaling = flat_flag;
		}
		bool HasRecVertex();
		Bool_t TOFPID(AliESDtrack* );
		Double_t EtaCalibration(const Double_t& );
		Bool_t PhiCut(Double_t , Double_t , Double_t , Float_t , TF1* , TF1* );
		Int_t GetPidCode(Int_t);


	protected:
	private:
		AliESDEvent *fESD; //! input ESD event
		AliEventCuts fEventCuts;
		AliStack *fMCStack; //! MC stack
		AliMCEvent *fMC;    //! MC Event
		Bool_t fUseMC;      // analyze MC events
		Int_t fV0Mindex;
		TString fV0MBin;
		TString fDetFlat;
		Bool_t fIsMCclosure;
		Bool_t fRemoveTrivialScaling;
		Int_t fnGen;
		AliPIDResponse* fPIDResponse;
		AliAnalysisFilter* fTrackFilter;
		AliAnalysisFilter* fTrackFilterPID;
		TList *fOutputList; //! output list in the root file
		Double_t fEtaCut;
		Double_t fPtMin;
		Double_t fNcl;
		Bool_t fdEdxCalibrated;
		TF1* fEtaCalibrationPos;
		TF1* fEtaCalibrationNeg;
		TF1* fcutLow;
		TF1* fcutHigh;
		TF1* fcutDCAxy;
		TString fPeriod;
		Double_t ftrackmult08;
		Double_t fv0mpercentile;
		Float_t fFlat;
		Float_t fFlatMC;
		AliMultSelection *fMultSelection;
		TH1D *hPtPrimIn;
		TH1D *hPtPrimOut;
		TH1D *hPtSecOut;
		TH1D *hPtOut;
		TH2D *hFlatV0vsFlatTPC;
		TH1F *hFlatenicityBefore;
		TH1D *hFlatenicity;
		TH1D *hFlatenicityMC;
		TH2D *hFlatResponse;
		TH2D *hFlatVsPt;
		TH2D *hFlatVsPtMC;
		TProfile *hActivityV0DataSect;
		TProfile *hActivityV0McSect;
		TH2D *hFlatVsNchMC;
		TH2F *hFlatVsV0M;
		TH1F *hCounter;
		TH2D *hFlatVsPtV0M[9];
		TH3F *hNsigmaPiPos[9][4];
		TH3F *hNsigmaKPos[9][4];
		TH3F *hNsigmaPPos[9][4];
		TH2F *hPtTPCEtaPos[9][4];
		TH3F *hNsigmaPiNeg[9][4];
		TH3F *hNsigmaKNeg[9][4];
		TH3F *hNsigmaPNeg[9][4];
		TH2F *hPtTPCEtaNeg[9][4];
		TH3F* hBetaPos[9][4];
		TH2F* hMomentumTOFEtaPos[9][4];
		TH2F* hPtTOFEtaPos[9][4];
		TH3F* hBetaNeg[9][4];
		TH2F* hMomentumTOFEtaNeg[9][4];
		TH2F* hPtTOFEtaNeg[9][4];
		TH3F* hdEdx[9][4];
		TH2F* hPtrTPC[9][4];
		TH2F* hPtVsP[4];
		TH2F* hKaonContamination[4];
		TH2F* hKaondEdx[4];
		TH2F* hProtonContamination[4];
		TH2F* hProtondEdx[4];
		TH2F* hPionTOFDCAxyNeg[3];
		TH2F* hProtonTOFDCAxyNeg[3];
		TH2F* hPionTOFDCAxyPos[3];
		TH2F* hProtonTOFDCAxyPos[3];
		TH2F* hPionTPCDCAxyNeg[3];
		TH2F* hProtonTPCDCAxyNeg[3];	
		TH2F* hPionTPCDCAxyPos[3];	
		TH2F* hProtonTPCDCAxyPos[3];
		
		TH1F* hMCPtPionPos;
		TH1F* hMCPtKaonPos;
		TH1F* hMCPtProtonPos;
		TH1F* hMCPtPionNeg;
		TH1F* hMCPtKaonNeg;
		TH1F* hMCPtProtonNeg;

		TH1F* hTPCRecTracksPionPos;
		TH1F* hTPCRecTracksKaonPos;
		TH1F* hTPCRecTracksProtonPos;
		TH1F* hTPCRecTracksPionNeg;
		TH1F* hTPCRecTracksKaonNeg;
		TH1F* hTPCRecTracksProtonNeg;

		TH1F* hTOFRecTracksPionPos;
		TH1F* hTOFRecTracksKaonPos;
		TH1F* hTOFRecTracksProtonPos;
		TH1F* hTOFRecTracksPionNeg;
		TH1F* hTOFRecTracksKaonNeg;
		TH1F* hTOFRecTracksProtonNeg;
		TH1F* hrTPCRecTracksPion;
		TH1F* hrTPCRecTracksKaon;
		TH1F* hrTPCRecTracksProton;
		TH2F* hPionTPCDCAxyNegData;
		TH2F* hPionTPCDCAxyPosData;
		TH2F* hProtonTPCDCAxyNegData; 
		TH2F* hProtonTPCDCAxyPosData;
		TH2F* hPionTOFDCAxyNegData;
		TH2F* hPionTOFDCAxyPosData;
		TH2F* hProtonTOFDCAxyNegData; 
		TH2F* hProtonTOFDCAxyPosData;
		TH2F* hMIPVsEta;
		TProfile* pMIPVsEta;
		TH2F* hPlateauVsEta;
		TProfile* pPlateauVsEta;

		AliAnalysisTaskFlatenicityPiKp(
				const AliAnalysisTaskFlatenicityPiKp &); // not implemented
		AliAnalysisTaskFlatenicityPiKp &
			operator=(const AliAnalysisTaskFlatenicityPiKp &); // not implemented

		ClassDef(AliAnalysisTaskFlatenicityPiKp, 3);
};

#endif