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

- Branch prediction : branch의 결과를 예상하여 파이프라인에 명령어를 집어넣고 혹시 branch의 결과에 대한 예상이 틀렸다면 파이프라인에 들어가있는 명령어들을 no operation 명령어로 바꾼다. (flush한다.)  prediction이 맞으면 그대로 진행하고 prediction이 틀렸을 경우 pipeline 안의 명령어들을 flush하고 bubble이 생성된다. 이럴 경우 클락 손실이 발생하게 되며 이를 **misprediction penalty**라고 한다.

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
  - 1 bit predictor의 경우 branch 여부를 확인하는 비트를 1개 쓴다. 2 bit predictor의 겨우 branch 여부를 확인하는 비트를 2개 쓴다. 00, 01은 branch 안함. 10, 11은 branch함. branch했을 경우 predictor 에 +1 (11일 경우는 안함) , branch 안했을 경우 predictor에 -1 (00일 경우는 안함) 이런 식으로 한번의 Branch로 영향을 단번에 받지 않게 되어 Branch taken 과 Branch not taken 을 반복하지 않게 된다.

- Delayed branch : branch를 1(or N)클락 이후에 실행하게 한다. Branch delay slot을 하나 만들어서 branch의 실행 여부에 상관 없이 실행되는 명령어를 집어넣고(없으면 `nop`) 그 명령어 이후에 (Branch 명령어가 ID stage일 때) branch가 실행되게 한다. 



## Direct Mapped Cache

Direct Mapped Cache: 메모리 주소와 캐시 주소가 그대로 매핑된다. 따라서 메모리의 특정 구역의 데이터는 캐시의 특정 구역에만 들어갈 수 있다.

#### Cache address

Cache address ( = Cache Index) : (Block address) % (Number of blocks in the cache) 의 값. 

다르게 말하자면 메모리 주소의 뒷 N(캐시의 크기에 따라 달라짐)자리. 

가령 Cache의 크기(number of entries in the cache)가 2^N 일때, Cache address는 메모리 주소의 하위 N 비트임

메모리 상위 N비트가 아닌 하위 N비트를 Index로 쓰는 이유: 데이터 지역성 때문



#### Cache 구성

캐시 구성				Index - Valid (1 bit) - Tag (20 bit) - Data (32 bit)

캐시 호출 				Tag - Index - (byte)offset 

Index는 캐시메모리의 몇번째에 접근할지를 결정한다. Index 값으로 접근하고 나면 주어진 Tag(= 메모리 주소의 상위 M 비트)와 캐시에 저장된 Tag를 비교하여 캐시에 있는 데이터가 원하는 값이 맞는지를 검사한다. 맞다면 hit, 아니라면 miss라고 한다. 

한번에 불러올 때 1바이트 단위가 아닌 1 워드 단위로 불러오므로 Least significant 2 bits를 활용하여(어차피 00으로 고정되서 안써도 되는 부위이므로) offset으로 활용한다. 4개의 바이트(=1워드)를 불러 왔을 때 00, 01, 10, 11 중 몇번째 바이트인지를 알려주는 역할을 한다. 



#### Cache Size

캐시의 크기를 말할 때 Data 부분의 크기들만 말한다.

가령 위의 경우 1024개의 캐시가 있다고 하면 실제 필요한 크기는 Valid 비트와 Tag 비트열을 포함하여6.625KiB 이지만 Data의 크기만 따지만 4KiB이므로 4KiB 캐시라고 한다. 



#### Multi-word Block Mapped Cache

위의 경우 예를 들어 100번지의 메모리를 캐시로 가져왔다고 했을 때 104 번지의 메모리를 접근하려고 할 때 hit하지 못하는 단점이 있다. 그래서 공간적 활용을 위해 한 블록을 1워드에서 4워드로 늘리도록 한다. 이제 Multiword Block Direct Mapped Cache다.

##### Block Offset

또한 캐시데이터를 호출하는데 있어서 Byte offset과 비슷하게 또 하위 2비트(3~2 번 비트)를 사용하지 않는데, 이를 Block Offset이라고 한다. 이는 한 블록 내에서 몇번째 워드를 가리키는지를 나타낸다. 

Offset이 Byte Offset 혼자 2비트에서 Block offset까지 4비트로 늘었으므로 캐시를 불러올 때의 32비트에서 가용 가능한 비트열이 2개 줄었다. 이 때 Index가 줄어들고 Tag는 그대로이다. 

우리는 4워드(32비트)로 비트를 늘렸지만 실제 많이 쓰이는 것은 64바이트=16워드 정도이다.

이땐 block offset이 더 늘어나므로 Index는 더 줄어들겠지?

#### Write-Back

메모리에 직접 읽고 쓰는 것은 느리기 때문에 중간에 캐시 메모리를 둔다. 그러나 캐시 메모리의 내용물이 바뀔때마다 메모리에 반영한다면은 캐시메모리를 두는 이유가 없다. 그래서 캐시메모리의 값이 바뀌었는데도 메모리의 값이 바뀌지 않다가 적절할 때에 메모리에 반영한다. 

#### Cache의 성능

cache miss 가 발생했을 때 메모리에서 cache로 데이터를 불러와야 하므로 그동안 memory-stall clock cycles만큼 기다려야 한다.

* Memory Stalls:  read-stalls + write-stalls

* Read-stall cycles = (reads/program) x read miss rate x read miss penalty

* Write-stall cycles = (writes/program) x write miss rate x write miss penalty + write buffer stalls

  강의자료 22-6을 참고.

캐시 성능을 개선하는 방법: 

1. Using associativity 
2. Multi-level caching

write buffer stalls 는 캐시에서 메모리로 쓰기 위한 버퍼가 다 차서 더 쓸 수 없을 때 생기는데, 자주 생기는 상황은 아니다. 

그러므로 신경써야 할 것은 miss rate 와 miss penalty인데 miss rate를 줄이기 위해 아래와 같은 방법을 고려할 수 있다.

- 3 placement schemes
  - Direct mapping
  - Set-associative mapping
  - Fully) associative mapping



## Fully associative cache

Direct mapped cache는 메모리 상의 특정 구역에 있는 데이터가 캐시의 특정 구역에만 들어갈 수 있었다. 더 유연한 배치를 사용하여 miss rate를 줄이기 위하여 Fully associative를 고려한다.

Fully associative mapping 방식을 사용한 캐시는 데이터가 cache 내 아무 장소에나 들어갈 수 있다.

따라서 Cache 활용도가 더 높아지고 miss rate로 내려간다.

그러나 CAM(Content Addressable Memory) 등 이전과는 다른 하드웨어들을 요구하기 때문에 쉽게 적용하기 힘들다.



## Set associative cache

Direct mapped 와 Fully associative의 절충안이다. 

N개의 Set으로 캐시를 구성하고 각 Set은 Index를 공유하며 각기 별도의 Valid bit, Tag, Data를 가지고 있다. 

Direct mapping = 1-way set associative mapping

fully associative = m-way set associative mapping (Cache size =m block)



miss가 발생했는데 캐시가 꽉 찼을 경우 이미 있는 데이터를 내보내야 한다. 이 때 내보낼 데이터의 선정 기준을 다양하게 선별할 수 있는데 이 중 일부는 다음과 같다.

* Least Recently Used : 가장 '최근에 사용되지 않은' 것을 내보낸다.



#### set associative cache address

tag - index - offset 으로 구성

offset : block size가 2^n일 경우 offset 은 n임.



#### cache size

n-way set associative cache (1 block = m byte) 의 크기는

n * index 수 * m byte 이다.

