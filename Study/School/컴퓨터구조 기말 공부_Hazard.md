# 컴퓨터구조 기말 시험 공부

## Data Hazard

#### Data Hazard가 발생할 조건

- Data dependence: 앞의 명령어로 뒤의 명령어가 영향을 받음. Data dependence graph를 그려서 확인!
- Two dependent instructions are close enough: 두 명령어가 충분히 가까워서 pipelined된 상황에서 앞 명령어의 쓰기가 끝나기 전에 뒤 명령어의 읽기가 실행됨



#### Data Hazard의 해결책

- Stalling: 하드웨어적 bubble(=`nop`) 삽입

- Insert `nop` Instructions: 소프트웨어적 `nop`삽입

- Code Scheduling (Pipeline Scheduling) : Data dependence가 존재하지 않는 명령어를 A와 B사이에 끼워넣음. 그게 어려울 경우 `nop`삽입. Static(컴파일러)과 Dynamic(CPU) 둘 다 존재.

- Forwarding : 앞선 명령어의 결과(즉, WB단계에서 레지스터에 쓰이는 값)를 WB단계에서 레지스터에 쓰기를 기다리지 않고, 레지스터를 경유하지 않고(Bypassing) EX단계의 결과 (EX/MEM 레지스터의 값)를 바로 가져온다. 가져온 값은 다음 명령어의 EX의 input값 중 하나로 바로 들어가게 된다. 강의자료 17-17의 그림을 참조할 것.  

  추가적인 연결과 데이터패스가 필요해지는 단점이 있다. 

  **Forwarding을 써도 Stalling이 필요한 경우가 있다.** 가령 `lw`명령어 같은 경우 4번째 MEM 단계의 끝(`MEM/WB reg`)에서 결과가 나오기 때문에 Forwarding 만으로는 다음 명령어의 EX단계(`ID/EX reg`)에서 값을 사용할 수가 없다. 따라서 1개의 bubble이 필요함. 강의자료 17-29의 그림을 참조할 것.

#### Hazard Condition

1a: `EX/MEM.RegisterRd=ID/EX.RegisterRS` : 바로 이웃한 명령어들간의 Hazard

1b.`EX/MEM.RegisterRd=ID/EX.RegisterRt`  : 1a랑 비슷하지만 이번엔 Rt다.

2a.`MEM/WB.RegisterRd=ID/EX.RegisterRs`  : 한 칸 떨어져 이웃한 명령어들간의 Hazard

2b.`MEM/WB.RegisterRd=ID/EX.RegisterRt` : 2a랑 비슷하지만 이번엔 Rt다.



## Control Hazard

Branch 명령어가 조건을 충족하여 Branch되느냐 마느냐로 Branch이후 처리될 명령어가 달라진다. 그런데 Branch 명령어의 조건 충족 여부는 EX단계에 가서야 알 수 있다. 

#### Solutions

- Stall on branch : 단순히 branch 명령어가 끝날 때까지 다음 명령어를 fetch하지 않음. 따라서 bubble이 발생. 이를 branch penalty 라고 한다.  MEM 단계에서 branch의 여부를 판단하고 그때까지 Stall하면 branch마다 3클락의 손실이 발생하게 되지만 ID 단계에서 branch의 여부를 판단하면 branch마다 1클락의 손실밖에 발생하지 않는다.

- Branch prediction : branch의 결과를 예상하여 파이프라인에 명령어를 집어넣고 혹시 branch의 결과에 대한 예상이 틀렸다면 파이프라인에 들어가있는 명령어들을 no operation 명령어로 바꾼다. (flush한다.)  prediction이 맞으면 그대로 진행하고 prediction이 틀렸을 경우 pipeline 안의 명령어들을 flush하고 bubble이 생성된다. 이럴 경우 클락 손실이 발생하게 되며 이를 misprediction penalty라고 한다.

  branch 결과의 예측 방법은 여러가지 있는데 Static branch prediction과 Dynamic branch prediction이 있다. 

  그중 Static branch prediction의 종류는 다음과 같다. 

  - Assume branch taken
  - Assume branch not taken
  - Prediction by opcode
  - Prediction by direction : 가령 반복문의 경우는 99번 되돌아가고 1번 앞으로 (반복문 탈출)가므로 뒤로가는 경우 branch될 확률이 높다.

  Dynamic branch prediction은 branch 명령어가 과거에 branch했음/안했음을 predictor에 기록해두었다가 나중에 branch prediction에 사용하는 방법이다. 따라서 runtime에 실행된다는 특징이 있다. Dynamic branch prediction의 종류는 다음과 같다.

  - branch history table(BHT)
    - 1-bit predictor
    - 2-bit predictor
  - Correlating branch predictor
  - Tournament branch predictor
  - Branch target buffer

  predictor는 1bit predictor와 2bit predictor가 있다. 

  - Branch history table(= branch prediction buffer) : 주소의 뒷부분(앞부분을 쓰면 중복될 확률이 높음)으로 인덱스된,  branch 여부를 나타내는 비트들이 있는 공간. 우연히 주소의 뒷부분이 겹치게 되어 서로 다른 branch명령어들의 결과를 하나의 비트에 저장(당연히 덮어쓰기)하게 될 수 있는데 성능에 별 차이가 없으므로 그냥 사용한다.
  - 1 bit predictor의 경우 branch 여부를 확인하는 비트를 1개 쓴다. 2 bit predictor의 겨우 branch 여부를 확인하는 비트를 2개 쓴다. 00, 01은 branch 안함. 10, 11은 branch함. branch했을 경우 predictor 에 +1 (11일 경우는 안함) , branch 안했을 경우 predictor에 -1 (00일 경우는 안함) 이런 식으로 한번의 \

- Delayed branch : branch를 1(or N)클락 이후에 실행하게 한다. Branch delay slot을 하나 만들어서 branch의 실행 여부에 상관 없이 실행되는 명령어를 집어넣고(없으면 `nop`) 그 명령어 이후에 (Branch 명령어가 ID stage일 때) branch가 실행되게 한다. 

