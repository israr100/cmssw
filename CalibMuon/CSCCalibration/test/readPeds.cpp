#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
  float peds,chi2;
  int index,flag,flag1;
  int nrlines=0;

  std::vector<int>   index_id;
  std::vector<float> Ped;
  std::vector<float> pedChi2;
  
  std::ifstream dbdata; 
  dbdata.open("FileName",std::ios::in);
  if(!dbdata) {
    std::cerr <<"Error: FileName -> no such file!"<< std::endl;
    exit(1);
  }

    float sumPedsME11(0), sumPchi2ME11(0), sumPedsME21(0), sumPchi2ME21(0), sumPedsME31(0), sumPchi2ME31(0), sumPedsME41(0), sumPchi2ME41(0);
    float avgPedsME11(0), avgPchi2ME11(0),  avgPedsME21(0), avgPchi2ME21(0),  avgPedsME31(0), avgPchi2ME31(0),  avgPedsME41(0), avgPchi2ME41(0);
    int nIndexME11(0), nIndexME21(0), nIndexME31(0), nIndexME41(0);
    
    float sumPedsME42(0), sumPchi2ME42(0);
    float avgPedsME42(0), avgPchi2ME42(0);
    int nIndexME42(0);

  while (!dbdata.eof() ) {
    dbdata >> index >> peds >>chi2 >>flag >>flag1; 
    index_id.push_back(index);
    Ped.push_back(peds);
    pedChi2.push_back(chi2);
    nrlines++;
      
      if ( ((index >= 252289 && index <= 273024) || (index >= 1 && index <= 17280) || (index >= 108865 && index <= 126144)) && (peds>1000.0 && peds<1300.0) ){
          sumPedsME11 += peds;
          sumPchi2ME11  += chi2;
          nIndexME11++;
      }

      if ( ((index >= 48385 && index <= 57024) || (index >= 157249 && index <= 165888)) && (peds>1000.0 && peds<1300.0) ){
          sumPedsME21 += peds;
          sumPchi2ME21  += chi2;
          nIndexME21++;
      }

      if ( ((index >= 74305 && index <= 82944) || (index >= 183169 && index <= 191808)) && (peds>1000.0 && peds<1300.0) ){
          sumPedsME31 += peds;
          sumPchi2ME31  += chi2;
          nIndexME31++;
      }

      if ( ((index >= 100225 && index <= 108864) || (index >= 209089 && index <= 217728)) && (peds>1000.0 && peds<1300.0) ){
          sumPedsME41 += peds;
          sumPchi2ME41  += chi2;
          nIndexME41++;
      }
      
      if ( (index >= 217729 && index <= 252288) && (peds>400.0 && peds<1000.0) ){
          sumPedsME42 += peds;
          sumPchi2ME42  += chi2;
          nIndexME42++;
      }
  }
    
    avgPedsME11 = sumPedsME11/nIndexME11;
    avgPchi2ME11  = sumPchi2ME11/nIndexME11;
    avgPedsME21 = sumPedsME21/nIndexME21;
    avgPchi2ME21  = sumPchi2ME21/nIndexME21;
    avgPedsME31 = sumPedsME31/nIndexME31;
    avgPchi2ME31  = sumPchi2ME31/nIndexME31;
    avgPedsME41 = sumPedsME41/nIndexME41;
    avgPchi2ME41  = sumPchi2ME41/nIndexME41;
    
    avgPedsME42 = sumPedsME42/nIndexME42;
    avgPchi2ME42  = sumPchi2ME42/nIndexME42;
    
  dbdata.close();
  std::ofstream myPedsFile("GoodVals_FileName",std::ios::out);
  std::cout<<"nrlines = "<<nrlines<<std::endl;

  for(int i=0; i<nrlines-1;++i){
      
    if ( (index_id[i] >= 252289 && index_id[i] <= 273024) || (index_id[i] >= 1 && index_id[i] <= 17280) || (index_id[i] >= 108865 && index_id[i] <= 126144)){
        if (Ped[i]>1000.0 && Ped[i]<1300.0){
            myPedsFile<<index_id[i]<<"  "<<Ped[i]<<"  "<<pedChi2[i]<<std::endl;
        }
        else{
            myPedsFile<<index_id[i]<<"  "<< avgPedsME11 <<"  "<< avgPchi2ME11 <<std::endl;
        }
    }
    else if ((index_id[i] >= 48385 && index_id[i] <= 57024)|| (index_id[i] >= 157249 && index_id[i] <= 165888)){
        if (Ped[i]>1000.0 && Ped[i]<1300.0){
            myPedsFile<<index_id[i]<<"  "<<Ped[i]<<"  "<<pedChi2[i]<<std::endl;
        }
        else{
            myPedsFile<<index_id[i]<<"  "<< avgPedsME21 <<"  "<< avgPchi2ME21 <<std::endl;
        }
    }
    else if ((index_id[i] >= 74305 && index_id[i] <= 82944)|| (index_id[i] >= 183169 && index_id[i] <= 191808)){
        if (Ped[i]>1000.0 && Ped[i]<1300.0){
            myPedsFile<<index_id[i]<<"  "<<Ped[i]<<"  "<<pedChi2[i]<<std::endl;
        }
        else{
            myPedsFile<<index_id[i]<<"  "<< avgPedsME31 <<"  "<< avgPchi2ME31 <<std::endl;
        }
    }
    else if ((index_id[i] >= 100225 && index_id[i] <= 108864)|| (index_id[i] >= 209089 && index_id[i] <= 217728)){
        if (Ped[i]>1000.0 && Ped[i]<1300.0){
            myPedsFile<<index_id[i]<<"  "<<Ped[i]<<"  "<<pedChi2[i]<<std::endl;
        }
        else{
            myPedsFile<<index_id[i]<<"  "<< avgPedsME41 <<"  "<< avgPchi2ME41 <<std::endl;
        }
    }
    else if (Ped[i]>400.0 && Ped[i]<1000.0){
      myPedsFile<<index_id[i]<<"  "<<Ped[i]<<"  "<<pedChi2[i]<<std::endl;
      if (flag==1 || flag1==1){
  std::cout<<"Flag not 0: "<<index_id[i]<<" " <<flag<<"  "<<flag1<<std::endl;
      }
    }
    else if ( index_id[i] >= 217729 && index_id[i] <= 252288 ){
        myPedsFile<<index_id[i]<<"  "<< avgPedsME42 <<"  "<< avgPchi2ME42 <<std::endl;
    }
      
  }
}
