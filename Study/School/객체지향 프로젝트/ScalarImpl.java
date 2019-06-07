package tensor;

import java.util.Random;

class ScalarImpl implements Scalar
{
    Double ScalarValue;

    ScalarImpl(){
        ScalarValue = 0d;
    }
    ScalarImpl(Double value){
        ScalarValue = value;
    }
    ScalarImpl(Double i, Double j){

    }

    @Override
    public Double getValue() {
        return ScalarValue;
    }

    @Override
    public void setValue(Double value) {
        ScalarValue = value;
    }

    @Override
    public void setValue(Double i, Double j) {
        Random random = new Random();
        ScalarValue = random.nextDouble()*(j-i) + i;
    }

    @Override
    public String toString() {
        return getValue().toString();
    }

    //객체의 동등성 판단을 할 수 있다.
    @Override
    public boolean equals(Object object) {
        ScalarImpl tmpScalar = (ScalarImpl)object;
        if(tmpScalar.getValue() == this.getValue())
            return true;
        else
            return false;
    }

    //스칼라의 경우 값의 대소 비교를 할 수 있다.
    @Override
    public int compareTo(Scalar another) {
        if(this.getValue() > another.getValue())
            return 1;
        else if(this.getValue() < another.getValue())
            return -1;
        else
            return 0;
    }

    //스칼라는 다른 스칼라와 덧셈이 가능하다. 연산 결과는 자신의 새로운 값이 된다.
    @Override
    public Scalar add(Scalar scalar) {
        this.setValue(this.getValue() + scalar.getValue());
        return this;
    }

    //스칼라는 다른 스칼라와 곱셈이 가능하다. 연산 결과는 자신의 새로운 값이 된다.
    @Override
    public Scalar mul(Scalar scalar) {
        this.setValue((this.getValue() * scalar.getValue()));
        return this;
    }

    @Override
    public Object clone() throws  CloneNotSupportedException {
        Scalar newScalar = (Scalar) super.clone();
        newScalar.setValue(ScalarValue);
        return newScalar;
    }

}
