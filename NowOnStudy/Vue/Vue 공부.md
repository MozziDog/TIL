Vue 공부



# Vue를 사용하여 DOM 조작

선언적 렌더링 : 선언만 해줘도 그와 동시에 렌더링( = DOM 조작)됨

```
var app = new Vue({
  el: '#app', // 대상 엘리먼트
  data: {
    message: '안녕하세요 Vue!' // 해당 엘리먼트의 [message]를 지정
  }
})
```

최초 선언뿐만 아니라 값이 업데이트 되었을 때도 알아서 렌더링됨

```
app.message = '안녕히 계세요 Vue!'
```

Vue를 통해 HTML 엘리멘트를 조작할 수 있음



콧수염 문법 (`{{ }}`)을 사용하면 엘리먼트의 본문을 변수나 함수와 바인딩할 수 있음

```
<div>
	{{message}}
</div>
<!--엘리먼트 내부에서 [message]를 표시-->
```



`v-bind:`를 사용해서 엘리먼트의 속성 값을 vue.js의 변수와 바인딩할 수 있음.

```
<span v-bind:title="message">
  이 위에 마우스를 올려서 바인딩된 title을 표시
</span>
```



`v-if:`나 `v-for:` 를 사용해서 데이터에 따라 DOM 구조도 바꿀 수 있음

```html
<div id="app-3">
  <p v-if="seen">이제 나를 볼 수 있어요</p>
  <!--"seen"값이 true일 때만 렌더링 됨-->
</div>
```



```html
<div id="app">
  <li v-for="todo in todos">
    {{ todo.text }}
  </li>
</div>
```

```js
var app4 = new Vue({
  el: '#app-4',
  data: {
    todos: [
      { text: 'JavaScript 배우기' },
      { text: 'Vue 배우기' },
      { text: '무언가 멋진 것을 만들기' }
    ]
  }
})
```



# 사용자 입력 핸들링

`v-on` 디렉티브를 사용하여 사용자 입력에 따라 메소드를 호출되게 할 수 있음.

```html
<div id="app-5">
  <p>{{ message }}</p>
  <button v-on:click="reverseMessage">메시지 뒤집기</button>
</div>
```

```js
var app5 = new Vue({
  el: '#app-5',
  data: {
    message: '안녕하세요! Vue.js!'
  },
  methods: {
    reverseMessage: function () {
      this.message = this.message.split('').reverse().join('')
    }
  }
})
```



# Vue 컴포넌트

HTML 요소들을 떼어다가 Vue 컴포넌트로 만들고 그때그때 불러와서 사용할 수 있음. (재사용성)

```js
Vue.component('mytag', {
    props: ['todo'],
    template: '<li>This is a todo</li>'
})
// Vue.component("HTML 커스텀 태그명", 옵션 오브젝트)
```

```HTML
<ol>
    <mytag></mytag>
    <mytag></mytag>
</ol>
```



# Method

Vue에서는 데이터 뿐만 아니라 함수의 리턴 값을 DOM의 엘리먼트와 바인딩할 수 있다.

`methods` 속성 내부에 정의해두고 `data` 값을 바인딩했던 거랑 똑같이 쓰면 됨.

```js
new Vue({ 
  el: "#app", 
  data: {
    count: 0,
  },
  methods: {
    triple: function () {
      console.log('methods triple')
      return this.count * 3
    }
  }
})
```





# computed 속성

Vue 객체를 생성할 때 인자로 주는 옵션 오브젝트에는 `computed`라는 속성이 있다.

data가 바뀔 때마다 Vue에서는 그것을 인식하고 DOM을 다시 렌더링하는데, 그 때 불필요한 계산이 일어나지 않게끔 해주는 것이 computed 속성

위 목적에 따라, computed 속성으로 주어진 함수의 실행에는 아래와 같은 조건이 만족되어야 함

* DOM 엘리먼트에 해당 요소가 바인딩(출력)되어 있어야 함.
* 해당 함수에서 사용하는 값들이 변경되어야 함.

```js
new Vue({ 
  el: "#app", 
  data: {
    count: 0,
    secondCount: 0
  },
  computed: {
    double: function () {			// count가 바뀌었을 때에만 호출됨.
      console.log('Computed double')
      return this.count * 2
    }
  },
  methods: {
    triple: function () {			// secondCount가 바뀌었을 때에도 호출됨
      console.log('methods triple')
      return this.count * 3
    }
  }
})
```

위 예제에서 `method`와 바인딩 된 엘리먼트는 Vue로 관리되는 data 중 어떤 하나라도 바뀌었을 때 무조건 다시 호출되지만 `computed`는 오로지 `count`라는 특정 data값이 바뀌었을 경우에만 호출됨.



# watch 속성

특정 data값이 바뀌었을 때 호출되는 함수

```js
new Vue({
	el: "#app",
  data: {
    count: 3,
    text: '변경 전입니다.'
  },
  watch: {
    count: function (newVal, oldVal) {	// 인자 1개(newVal)만 받는 함수로 해도 됨
      this.text = oldVal + '에서 ' + newVal + '로 변경되었습니다.'
    }
  }
})
```

`computed`는 불필요한 계산의 생략이 목적이었다면, `watch`는 data가 변경되었을 때 호출되는 좀 더 범용적인 목적임.



# 최적화 : data는 함수로

data를 일반적인 데이터로 선언하면 **모든** Vue 컴포넌트의 인스턴스가 해당 값의 복사본을 가지고 있게 됨. 그러나 똑같은 값을 리턴하는 함수로 선언해주면 그러한 현상을 막을 수 있음.
