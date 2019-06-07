package tensor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.ListIterator;

public class VectorImpl implements Vector {

    ArrayList<Scalar> VectorValue;

    VectorImpl() {
        VectorValue = new ArrayList<>();
    }

    VectorImpl(int dimension, Double value) {
        VectorValue = new ArrayList<>();
        setVector(dimension, value);
    }

    VectorImpl(Double[] arr) {
        VectorValue = new ArrayList<>();
        setVector(arr);
    }

    VectorImpl(Scalar[] arr) {
        VectorValue = new ArrayList<>();
        setVector(arr);
    }

    VectorImpl(ArrayList<Scalar> value) {
        VectorValue = (ArrayList<Scalar>)value.clone();
    }

    //지정한 하나의 값을 모든 요소의 값으로 하는 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(int dimension, Double value) throws SizeLessThanZeroException {
        if(dimension < 0)
            throw new SizeLessThanZeroException();
        VectorValue.clear();
        for(int i=0; i<dimension; i++)
            VectorValue.add(new ScalarImpl(value));
    }

    //지정한 하나의 값을 모든 요소의 값으로 하는 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(int dimension, Scalar scalar) throws SizeLessThanZeroException {
        if(dimension < 0)
            throw new SizeLessThanZeroException();
        VectorValue.clear();
        for(int i=0; i<dimension; i++)
            VectorValue.add(scalar);
    }

    //i 이상 j 미만의 무작위 값을 요소로 하는 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(int dimension, Double i, Double j) throws SizeLessThanZeroException {
        if(dimension < 0)
            throw new SizeLessThanZeroException();
        VectorValue.clear();
        for(int idx=0; idx<dimension; idx++)
            VectorValue.add(new ScalarImpl(i, j));
    }

    //i 이상 j 미만의 무작위 값을 요소로 하는 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(int dimension, Scalar i, Scalar j) throws SizeLessThanZeroException {
        if(dimension < 0)
            throw new SizeLessThanZeroException();
        VectorValue.clear();
        for(int idx=0; idx<dimension; idx++)
            VectorValue.add(new ScalarImpl(i.getValue(), j.getValue()));
    }

    //1차원 배열로부터 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(Double[] arr) throws SizeLessThanZeroException {
        if(arr.length < 0)
            throw new SizeLessThanZeroException();
        VectorValue.clear();
        for(int idx=0; idx < arr.length; idx++)
            VectorValue.add(new ScalarImpl(arr[idx]));
    }

    //1차원 배열로부터 n-차원 벡터를 생성할 수 있다.
    @Override
    public void setVector(Scalar[] arr) throws SizeLessThanZeroException {
        if(arr.length < 0)
            throw new SizeLessThanZeroException();
        VectorValue = new ArrayList<>(Arrays.asList(arr));
    }

    // 특정 위치의 요소를 지정/조회할 수 있다. (스칼라로 입출력)
    @Override
    public void update(int col, Scalar scalar) throws IndexOutOfBoundException {
        if(col < 0 || col >= VectorValue.size())
            throw new IndexOutOfBoundException();
        VectorValue.set(col, scalar);
    }

    // 특정 위치의 요소를 지정/조회할 수 있다. (스칼라로 입출력)
    @Override
    public Scalar getScalar(int col) throws IndexOutOfBoundException {
        if(col < 0 || col >= VectorValue.size())
            throw new IndexOutOfBoundException();
        return VectorValue.get(col);
    }

    //크기 정보를 조회할 수 있다. (벡터는 차원, 행렬은 행개수, 열개수)
    @Override
    public int getSize() {
        return VectorValue.size();
    }

    //객체를 콘솔에 출력할 수 있다.
    @Override
    public String toString() {
        StringBuffer tmpString = new StringBuffer();
        for(ListIterator<Scalar> iter = VectorValue.listIterator(); iter.hasNext(); ) {
            tmpString.append(iter.next().toString());
            tmpString.append("\t");
        }
        return tmpString.toString();
    }

    //객체의 동등성 판단을 할 수 있다.
    @Override
    public boolean equals(Object object) {
        VectorImpl tmpVector = (VectorImpl)object;
        if(tmpVector.getSize() != this.getSize())
            return false;
        for(int idx =0; idx < getSize(); idx ++) {
            if(this.getScalar(idx).getValue() != tmpVector.getScalar(idx).getValue())
                return false;
        }
        return true;
    }

    //벡터는 다른 벡터와 덧셈이 가능하다. (길이가 같을 때) 연산 결과는 자신의 새로운 값이 된다.
    @Override
    public Vector add(Vector vector) throws SizeMismatchException {
        if(this.VectorValue.size() != vector.getSize())
            throw new SizeMismatchException();
        else {
            Double[] product = new Double[getSize()];
            for (int idx = 0; idx < getSize(); idx++)
                product[idx] = this.getScalar(idx).getValue() + vector.getScalar(idx).getValue();
            this.setVector(product);
            return this;
        }
    }

    //벡터는 다른 스칼라와 곱셈이 가능하다. (벡터의 모든 요소에 스칼라를 곱한다.) 연산 결과는 자신의 새로운 값이 된다.
    @Override
    public Vector mul(Scalar scalar) {
        Scalar[] product = new Scalar[getSize()];
        for(int idx = 0; idx < getSize(); idx ++)
            product[idx] = this.getScalar(idx).mul(scalar);
        this.setVector(product);
        return this;
    }

    //n-차원 벡터 객체는 자신으로부터 nx1 행렬을 생성하여 반환할 수 있다.
    @Override
    public Matrix toMatrixNx1() {
        Matrix tmpMatrix = new MatrixImpl(this.getSize(), 1, 0d);
        for(int idx =0; idx<this.getSize(); idx ++) {
            tmpMatrix.setMatrix(idx, 0, this.getScalar(idx));
        }
        return tmpMatrix;
    }

    //n-차원 벡터 객체는 자신으로부터 1xn 행렬을 생성하여 반환할 수 있다.
    @Override
    public Matrix toMatrix1xN() {
        ArrayList<ArrayList<Scalar>> tmpMatrixValue = new ArrayList<>();
        tmpMatrixValue.add(this.VectorValue);
        return new MatrixImpl(tmpMatrixValue);
    }


    //클론 함수 오버라이딩
    @Override
    public Object clone() throws CloneNotSupportedException {
        Vector newVector = (Vector) super.clone();
        newVector.setVector((Scalar[])VectorValue.toArray());
        return newVector;
    }

    public ArrayList<Scalar> getVectorArray(){
        return (ArrayList<Scalar>) VectorValue.clone();
    }
}
