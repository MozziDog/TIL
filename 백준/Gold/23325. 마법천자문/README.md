# [Gold IV] 마법천자문 - 23325 

[문제 링크](https://www.acmicpc.net/problem/23325) 

### 성능 요약

메모리: 3508 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 1월 4일 17:47:47

### 문제 설명

<p>최근<sup>最近</sup> 만화<sup>漫畫</sup> 마법천자문<sup>魔法千字文</sup>을 감명<sup>感銘</sup> 깊게 읽은 연두<sup>然斗</sup>는, 모든 수<sup>數</sup>를 한자<sup>漢字</sup>로 적기 시작<sup>始作</sup>했다. 그런데 수업<sup>授業</sup>을 들으면서 필기<sup>筆記</sup> 해놓은 내용<sup>內容</sup>을 복습<sup>復習</sup>하던 도중<sup>途中</sup>, 도저<sup>到底</sup>히 알아볼 수 없는 식<sup>式</sup>을 발견<sup>發見</sup>했다.</p>

<p style="text-align: center;"><code>+----+-+-</code></p>

<p>알고 보니 이 식은 숫자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10$</span></mjx-container>을 나타내는 "열 십 (十)"과 더하기를 나타내는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>+</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$+$</span></mjx-container>, 숫자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>을 나타내는 "한 일 (一)"과 빼기를 나타내는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-$</span></mjx-container>가 뒤섞여 있어 알아볼 수 없던 것이었다. 이 식은 수많은 해석이 가능해서, 이왕이면 식의 계산 결과가 가장 큰 해석을 찾아보기로 했다. 마법천자문 정주행에 바쁜 연두를 대신해 여러분이 그 결과를 대신 찾아주자.</p>

<p>올바른 해석의 정의는 다음과 같다.</p>

<ul>
	<li>올바른 해석은 <code><수></code>, <code><수><연산자><수></code>, <code><수><연산자><수><연산자><수></code>, … 의 꼴이어야 한다.

	<ul>
		<li>즉, <code><수></code>로 시작해서 <code><수></code>로 끝나며, <code><수></code>와 <code><연산자></code>가 번갈아가며 위치해야 한다.</li>
	</ul>
	</li>
	<li><code><수></code>는 <code>+-</code>, <code>+</code>, <code>-</code> 중 하나이며, 각각 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>11</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$11$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>로 해석된다.</li>
	<li><code><연산자></code>는 <code>+</code>, <code>-</code> 중 하나이며, 각각 더하기, 빼기로 해석된다.
	<ul>
		<li><code>-</code>를 음의 부호로는 쓸 수 없는 것에 주의하자. 예를 들어, <code>--</code>는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-1$</span></mjx-container>이 될 수 없다.</li>
	</ul>
	</li>
</ul>

### 입력 

 <p>첫 번째 줄에 <code>+</code>, <code>-</code>로 이루어진 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>200</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$200\,000$</span></mjx-container> 이하인 문자열이 주어진다.</p>

<p>반드시 하나 이상의 올바른 해석이 존재하는 입력만 주어진다.</p>

### 출력 

 <p>주어진 문자열의 올바른 해석 중, 가장 큰 계산 결과를 출력한다. </p>

