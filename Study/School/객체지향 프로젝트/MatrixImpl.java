package tensor;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.ListIterator;

public class MatrixImpl implements Matrix {

    ArrayList<ArrayList<Scalar>> MatrixValue;

    MatrixImpl() {
        MatrixValue = new ArrayList<>();
    }

    MatrixImpl(int row, int col, Double value) {
        MatrixValue = new ArrayList<>();
        setMatrix(row, col, value);
    }

    MatrixImpl(int row, int col, Scalar value) {
        MatrixValue = new ArrayList<>();
        setMatrix(row, col, value);
    }

    MatrixImpl(ArrayList<ArrayList<Scalar>> value) {
        MatrixValue = (ArrayList<ArrayList<Scalar>>) value.clone();
    }


    public final int CONCAT_DIRECTION_HORIZONTAL = 0;
    public final int CONCAT_DIRECTION_VERTICAL = 1;

    //지정한 하나의 값을 모든 요소의 값으로 하는 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(int row, int col, Double value) throws SizeLessThanZeroException {
        if (row < 0 || col < 0)
            throw new SizeLessThanZeroException();
        else {
            MatrixValue.clear();
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            for (int idx1 = 0; idx1 < row; idx1++) {
                for (int idx2 = 0; idx2 < col; idx2++) {
                    tmpRow.add(new ScalarImpl(value));
                }
                MatrixValue.add((ArrayList<Scalar>) tmpRow.clone());
                tmpRow.clear();
            }
        }
    }

    //지정한 하나의 값을 모든 요소의 값으로 하는 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(int row, int col, Scalar scalar) throws SizeLessThanZeroException {
        if (row < 0 || col < 0)
            throw new SizeLessThanZeroException();
        else {
            MatrixValue.clear();
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            for (int idx1 = 0; idx1 < row; idx1++) {
                for (int idx2 = 0; idx2 < col; idx2++) {
                    tmpRow.add(scalar);
                }
                MatrixValue.add((ArrayList<Scalar>) tmpRow.clone());
                tmpRow.clear();
            }
        }
    }

    //i 이상 j 미만의 무작위 값을 요소로 하는 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(int row, int col, Double i, Double j) throws SizeLessThanZeroException {
        if (row < 0 || col < 0)
            throw new SizeLessThanZeroException();
        else {
            MatrixValue.clear();
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            for (int idx1 = 0; idx1 < row; idx1++) {
                for (int idx2 = 0; idx2 < col; idx2++) {
                    tmpRow.add(new ScalarImpl(i, j));
                }
                MatrixValue.add((ArrayList<Scalar>) tmpRow.clone());
                tmpRow.clear();
            }
        }
    }

    //i 이상 j 미만의 무작위 값을 요소로 하는 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(int row, int col, Scalar i, Scalar j) throws SizeLessThanZeroException {
        if (row < 0 || col < 0)
            throw new SizeLessThanZeroException();
        else {
            MatrixValue.clear();
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            for (int idx1 = 0; idx1 < row; idx1++) {
                for (int idx2 = 0; idx2 < col; idx2++) {
                    tmpRow.add(new ScalarImpl(i.getValue(), j.getValue()));
                }
                MatrixValue.add((ArrayList<Scalar>) tmpRow.clone());
                tmpRow.clear();
            }
        }
    }

    //csv 파일로부터 m x n 행렬을 생성할 수 있다. csv 파일 형식: comma(,)는 열 구분자, 라인은 행 구분자 2 x 4 행렬 예) 1, 2, 3, 4, 2 x 4 행렬 예) 5, 6, 7, 8
    @Override
    public void setMatrix(String csv) throws SizeLessThanZeroException, WrongCSVFormatException {
        String[] csvSplitRows = csv.split("\n");
        String[] csvSplitScalars;
        ArrayList<Scalar> tmpRow = new ArrayList<>();
        try {
            ArrayList<ArrayList<Scalar>> tmpMatrix = new ArrayList<>();
            for (int idx1 = 0; idx1 < csvSplitRows.length; idx1++) {
                csvSplitScalars = csvSplitRows[idx1].split(",");
                for (int idx2 = 0; idx2 < csvSplitScalars.length; idx2++)
                    tmpRow.add(new ScalarImpl(Double.parseDouble(csvSplitScalars[idx2])));
                tmpMatrix.add(tmpRow);
                tmpRow.clear();
            }
            MatrixValue = tmpMatrix;
        } catch (NullPointerException nullptrE) {
            throw new SizeLessThanZeroException();
        } catch (NumberFormatException numformatE) {
            throw new WrongCSVFormatException();
        }
    }

    //2차원 배열로부터 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(Double[][] arr) throws SizeLessThanZeroException {
        if (arr.length < 0)
            throw new SizeLessThanZeroException();
        else {
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            MatrixValue.clear();
            for (int idx1 = 0; idx1 < arr.length; idx1++) {
                for (int idx2 = 0; idx2 < arr[1].length; idx2++) {
                    tmpRow.add(new ScalarImpl(arr[idx1][idx2]));
                }
                MatrixValue.add(tmpRow);
            }
        }
    }

    //2차원 배열로부터 m x n 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(Scalar[][] arr) throws SizeLessThanZeroException {
        if (arr.length < 0)
            throw new SizeLessThanZeroException();
        else {
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            MatrixValue.clear();
            for (int idx1 = 0; idx1 < arr.length; idx1++) {
                for (int idx2 = 0; idx2 < arr[1].length; idx2++) {
                    tmpRow.add(arr[idx1][idx2]);
                }
                MatrixValue.add(tmpRow);
            }
        }
    }

    //단위 행렬을 생성할 수 있다.
    @Override
    public void setMatrix(int n) throws SizeLessThanZeroException {
        if (n < 0)
            throw new SizeLessThanZeroException();
        else {
            MatrixValue.clear();
            ArrayList<Scalar> tmpRow = new ArrayList<>();
            for (int idx1 = 0; idx1 < n; idx1++) {
                for (int idx2 = 0; idx2 < n; idx2++) {
                    if (idx1 == idx2)
                        tmpRow.add(new ScalarImpl(1d));
                    else
                        tmpRow.add(new ScalarImpl(0d));
                }
                MatrixValue.add(tmpRow);
            }
        }
    }

    // 특정 위치의 요소를 지정/조회할 수 있다. (스칼라로 입출력)
    @Override
    public void update(int row, int col, Scalar scalar) throws IndexOutOfBoundException {
        ArrayList<Scalar> tmpRow = MatrixValue.get(row);
        tmpRow.set(col, scalar);
        MatrixValue.set(row, tmpRow);
    }

    // 특정 위치의 요소를 지정/조회할 수 있다. (스칼라로 입출력)
    @Override
    public Scalar getScalar(int row, int col) throws IndexOutOfBoundException {
        return MatrixValue.get(row).get(col);
    }

    //크기 정보(행 개수)를 조회할 수 있다. (벡터는 차원, 행렬은 행개수, 열개수)
    @Override
    public int getSizeRow() {
        return MatrixValue.size();
    }

    //크기 정보(열 개수)를 조회할 수 있다. (벡터는 차원, 행렬은 행개수, 열개수)
    @Override
    public int getSizeCol() {
        return MatrixValue.get(0).size();
    }

    //객체를 콘솔에 출력할 수 있다.
    @Override
    public String toString() {
        StringBuffer tmpString = new StringBuffer();
        for (int idx1 = 0; idx1 < MatrixValue.size(); idx1++) {
            for (ListIterator<Scalar> iter = MatrixValue.get(idx1).listIterator(); iter.hasNext(); ) {
                tmpString.append(iter.next().toString());
                tmpString.append("\t");
            }
            tmpString.append("\n");
        }
        return tmpString.toString();
    }

    //객체의 동등성 판단을 할 수 있다.
    @Override
    public boolean equals(Object object) {
        MatrixImpl tmpMatrix = (MatrixImpl) object;
        if (tmpMatrix.getSizeRow() != this.getSizeRow() || tmpMatrix.getSizeCol() != this.getSizeCol())
            return false;
        for (int idx1 = 0; idx1 < getSizeRow(); idx1++) {
            for (int idx2 = 0; idx2 < getSizeCol(); idx2++) {
                if (this.getScalar(idx1, idx2).getValue() != tmpMatrix.getScalar(idx1, idx2).getValue())
                    return false;
            }
        }
        return true;
    }

    //행렬은 다른 행렬과 덧셈이 가능하다. (크기가 같을 때)
    @Override
    public Matrix add(Matrix matrix) throws SizeMismatchException {
        if (this.getSizeRow() != matrix.getSizeRow() || this.getSizeCol() != matrix.getSizeCol())
            throw new SizeMismatchException();
        else {
            for (int idx1 = 0; idx1 < getSizeRow(); idx1++) {
                for (int idx2 = 0; idx2 < getSizeCol(); idx2++) {
                    setMatrix(idx1, idx2, this.getScalar(idx1, idx2).getValue() + getScalar(idx1, idx2).getValue());
                }
            }
        }
        return this;
    }

    //행렬은 다른 행렬과 곱셈이 가능하다. ((mxn)x(nxl)일 때)
    // 다른 행렬이 왼쪽 행렬로서 곱해지는 경우와 오른쪽 행렬로서 곱해지는 경우 모두 지원 => isOperand=true -> this.matrix * matrix, isOperand=false -> matrix * this.matrix
    @Override
    public Matrix mul(Matrix matrix, boolean isOperand) throws SizeMismatchException {
        if (isOperand) {
            if (this.getSizeCol() != matrix.getSizeRow() || matrix.getSizeCol() != 1)
                throw new SizeMismatchException();
            else { // m*1 사이즈
                ArrayList<ArrayList<Scalar>> tmpMatrix = new ArrayList<>();
                for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
                    Double tmpDouble = 0d;
                    for (int idx2 = 0; idx2 < this.getSizeCol(); idx2++) {
                        tmpDouble += this.getScalar(idx1, idx2).getValue() * matrix.getScalar(idx2, 0).getValue();
                    }
                    ArrayList<Scalar> tmpRow = new ArrayList<>();
                    tmpRow.add(new ScalarImpl(tmpDouble));
                    tmpMatrix.add(tmpRow);
                }
                this.MatrixValue = tmpMatrix;
                return this;
            }
        } else {
            if (matrix.getSizeCol() != this.getSizeCol() || this.getSizeCol() != 1)
                throw new SizeMismatchException();
            else { // 1*m 사이즈
                ArrayList<ArrayList<Scalar>> tmpMatrix = new ArrayList<>();
                for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
                    Double tmpDouble = 0d;
                    for (int idx2 = 0; idx2 < this.getSizeCol(); idx2++) {
                        tmpDouble += matrix.getScalar(idx1, idx2).getValue() * this.getScalar(idx2, 0).getValue();
                    }
                    ArrayList<Scalar> tmpRow = new ArrayList<>();
                    tmpRow.add(new ScalarImpl(tmpDouble));
                    tmpMatrix.add(tmpRow);
                }
                this.MatrixValue = tmpMatrix;
                return this;
            }
        }
    }

    //행렬은 특정 행을 벡터 형태로 추출해 줄 수 있다. (행 벡터 추출)
    @Override
    public Vector getVectorRow(int row) throws IndexOutOfBoundException {
        return new VectorImpl(this.MatrixValue.get(row));
    }

    //행렬은 특정 열을 벡터 형태로 추출해 줄 수 있다. (열 벡터 추출)
    @Override
    public Vector getVectorCol(int col) throws IndexOutOfBoundException {
        ArrayList<Scalar> tmpVectorValue = new ArrayList<>();
        for (int idx = 0; idx < this.getSizeRow(); idx++) {
            tmpVectorValue.add(this.getScalar(idx, col));
        }
        return new VectorImpl(tmpVectorValue);
    }

    //행렬은 특정 범위의 부분 행렬을 추출해 줄 수 있다.
    @Override
    public Matrix getSubMatrix(int startRow, int startCol, int endRow, int endCol) throws IndexOutOfBoundException {
        ArrayList<ArrayList<Scalar>> tmpMatrixValue = new ArrayList<>();
        ArrayList<Scalar> tmpRow = new ArrayList<>();
        for (int idx1 = startRow; idx1 <= endRow; idx1++) {
            tmpRow.clear();
            for (int idx2 = startCol; idx2 <= endCol; idx2++) {
                tmpRow.add(this.getScalar(idx1, idx2));
            }
            tmpMatrixValue.add(tmpRow);
        }
        return new MatrixImpl(tmpMatrixValue);
    }

    //행렬은 특정 범위의 부분 행렬을 추출해 줄 수 있다.
    @Override
    public Matrix getMinorMatrix(int row, int col) throws IndexOutOfBoundException {
        ArrayList<ArrayList<Scalar>> tmpMatrixValue = new ArrayList<>();
        ArrayList<Scalar> tmpRow = new ArrayList<>();
        for (int idx1 = 0; idx1 <= this.getSizeRow(); idx1++) {
            if (idx1 != row) {
                tmpRow.clear();
                for (int idx2 = 0; idx2 <= this.getSizeCol(); idx2++) {
                    if (idx2 != col)
                        tmpRow.add(this.getScalar(idx1, idx2));
                }
                tmpMatrixValue.add(tmpRow);
            }
        }
        return new MatrixImpl(tmpMatrixValue);
    }

    //행렬은 전치행렬을 (새로 생성하여) 구해줄 수 있다. (transpose)
    @Override
    public Matrix getTranspose() {
        ArrayList<ArrayList<Scalar>> tmpMatrixValue = new ArrayList<>();
        ArrayList<Scalar> tmpRow = new ArrayList<>();
        for (int idx1 = 0; idx1 <= this.getSizeCol(); idx1++) {
            tmpRow.clear();
            for (int idx2 = 0; idx2 <= this.getSizeRow(); idx2++) {
                tmpRow.add(this.getScalar(idx2, idx1));
            }
            tmpMatrixValue.add(tmpRow);
        }
        return new MatrixImpl(tmpMatrixValue);
    }

    //행렬은 대각 요소의 합을 구해줄 수 있다. (nxn 행렬) (trace)
    @Override
    public Scalar getTrace() {
        Scalar tmpScalar = new ScalarImpl(0d);
        for (int idx = 0; idx < this.getSizeRow(); idx++) {
            tmpScalar.add(this.getScalar(idx, idx));
        }
        return tmpScalar;
    }

    //행렬은 자신이 정사각 행렬인지 여부를 판별해 줄 수 있다.
    @Override
    public boolean isSquareMatrix() {
        if (this.getSizeRow() == this.getSizeCol())
            return true;
        else
            return false;
    }

    //행렬은 자신이 상삼각 행렬인지 여부를 판별해 줄 수 있다. (nxn 행렬) (upper triangular matrix)
    @Override
    public boolean isUpperTriangleMatrix() {
        if (!isSquareMatrix())
            return false;
        for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
            for (int idx2 = 0; idx2 < idx1 - 1; idx2++) {
                if (getScalar(idx1, idx2).getValue() != 0)
                    return false;
            }
        }
        return true;
    }

    //행렬은 자신이 하삼각 행렬인지 여부를 판별해 줄 수 있다. (nxn 행렬) (lower triangular matrix)
    @Override
    public boolean isLowerTriangleMatrix() {
        if (!isSquareMatrix())
            return false;
        for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
            for (int idx2 = idx1 + 1; idx2 < this.getSizeCol(); idx2++) {
                if (getScalar(idx1, idx2).getValue() != 0)
                    return false;
            }
        }
        return true;
    }

    //행렬은 자신이 단위 행렬인지 여부를 판별해 줄 수 있다. (nxn 행렬) (identity matrix)
    @Override
    public boolean isIdentityMatrix() {
        if (!isSquareMatrix())
            return false;
        for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
            for (int idx2 = 0; idx2 < this.getSizeCol(); idx2++) {
                if (idx1 == idx2) {
                    if (this.getScalar(idx1, idx2).getValue() != 1)
                        return false;
                } else if (this.getScalar(idx1, idx2).getValue() != 0)
                    return false;
            }
        }
        return true;
    }

    //행렬은 자신이 영 행렬인지 여부를 판별해 줄 수 있다. (zero matrix)
    @Override
    public boolean isZeroMatrix() {
        for (int idx1 = 0; idx1 < this.getSizeRow(); idx1++) {
            for (int idx2 = 0; idx2 < this.getSizeCol(); idx2++) {
                if (this.getScalar(idx1, idx2).getValue() != 0)
                    return false;
            }
        }
        return true;
    }

    /* TIP : 아래 6개 기능은 기본행렬 곱해서 만들면 쉽다.  */
    //행렬은 특정 두 행의 위치를 맞교환할 수 있다.
    @Override
    public Matrix rowSwitchTransform(int row1, int row2) throws IndexOutOfBoundException {
        Scalar tmp;
        for (int idx = 0; idx < this.getSizeCol(); idx++) {
            tmp = this.getScalar(row1, idx);
            this.setMatrix(row1, idx, this.getScalar(row2, idx));
            this.setMatrix(row2, idx, tmp);
        }
        return this;
    }

    //행렬은 특정 두 열의 위치를 맞교환할 수 있다.
    @Override
    public Matrix colSwitchTransform(int col1, int col2) throws IndexOutOfBoundException {
        Scalar tmp;
        for (int idx = 0; idx < this.getSizeRow(); idx++) {
            tmp = this.getScalar(idx, col1);
            this.setMatrix(idx, col1, this.getScalar(idx, col2));
            this.setMatrix(idx, col2, tmp);
        }
        return this;
    }

    //행렬은 특정 행에 상수배(스칼라)를 할 수 있다.
    @Override
    public Matrix rowMultiplyTransform(int row, Scalar scalar) throws IndexOutOfBoundException {
        for (int idx = 0; idx < this.getSizeCol(); idx++) {
            this.setMatrix(row, idx, this.getScalar(row, idx).getValue() * scalar.getValue());
        }
        return this;
    }

    //행렬은 특정 열에 상수배(스칼라)를 할 수 있다.
    @Override
    public Matrix colMultiplyTransform(int col, Scalar scalar) throws IndexOutOfBoundException {
        for (int idx = 0; idx < this.getSizeRow(); idx++) {
            this.setMatrix(idx, col, this.getScalar(idx, col).getValue() * scalar.getValue());
        }
        return this;
    }

    //행렬은 특정 행에 다른 행의 상수배를 더할 수 있다.
    @Override
    public Matrix rowAdditionTransform(int destinationRow, int sourceRow, Scalar scalar) throws IndexOutOfBoundException {// M[destinationRow] += scalar * M[sourceRow]
        if(destinationRow < 0 || destinationRow > this.getSizeRow() || sourceRow < 0 || sourceRow > this.getSizeRow())
            throw new IndexOutOfBoundException();
        else {
            for (int idx = 0; idx < this.getSizeCol(); idx++) {
                this.setMatrix(destinationRow, idx, this.getScalar(destinationRow, idx).getValue() + this.getScalar(sourceRow, idx).getValue() * scalar.getValue());
            }
            return this;
        }
    }

    //행렬은 특정 열에 다른 열의 상수배를 더할 수 있다.
    @Override
    public Matrix colAdditionTransform(int destinationCol, int sourceCol, Scalar scalar) throws IndexOutOfBoundException { // M[destinationCol] += scalar * M[sourceCol]
        if(destinationCol < 0 || destinationCol > this.getSizeCol() || sourceCol < 0 || sourceCol > this.getSizeCol())
            throw new IndexOutOfBoundException();
        else {
            for (int idx = 0; idx < this.getSizeCol(); idx++) {
                this.setMatrix(idx, destinationCol, this.getScalar(idx, destinationCol).getValue() + this.getScalar(idx, sourceCol).getValue() * scalar.getValue());
            }
            return this;
        }
    }

    //행렬은 자신으로부터 RREF 행렬을 구해서 반환해 줄 수 있다. (row reduced echelon form)
    @Override
    public Matrix getRREF() {
        try {
            Matrix RREF = (Matrix)this.clone();
            for (int p = 0; p < RREF.getSizeRow(); p++)
            {
                /* Make this pivot 1 */
                double pivot = RREF.getScalar(p, p).getValue();
                if (pivot != 0)
                {
                    RREF.rowMultiplyTransform(p, new ScalarImpl(1d/pivot));
                }

                /* Make other rows zero */
                for (int r = 0; r < RREF.getSizeRow(); ++r)
                {
                    if (r != p)
                    {
                        RREF.rowAdditionTransform(r, p, (Scalar)RREF.getScalar(r,p).clone());
                    }
                }
            }
            return RREF;
        }
        catch(CloneNotSupportedException e)
        {
            System.out.println("It's impossible");
            return null;
        }
    }

    //행렬은 자신이 RREF 행렬인지 여부를 판별해 줄 수 있다.
    @Override
    public boolean isRREF() {
        //조건 1. 모든 null row는 not-null row보다 아래에 있어야 함.
        boolean[] checkList1 = new boolean[this.getSizeRow()];
        Arrays.fill(checkList1, false); //null row가 false, not-null row가 true
        for(int idx1 = 0; idx1<this.getSizeRow(); idx1++) {
            for(int idx2 = 0; idx2<this.getSizeCol(); idx2 ++) {
                if(this.getScalar(idx1, idx2).getValue() != 0d)
                    checkList1[idx1] = true;
            }
        }
        for(int idx =0; idx<checkList1.length-1; idx ++)
        {
            if(checkList1[idx] == false && checkList1[idx+1] == true)
                return false;
        }
        //조건 2. not-null row에서 선행 계수는 그 윗줄의 선행 계수보다 오른쪽에 있어야 함.
        int[] checkList2 = new int[this.getSizeRow()];
        for(int idx1 = 0; idx1<this.getSizeRow(); idx1++) {
            for(int idx2 = 0; idx2<this.getSizeCol(); idx2 ++) {
                if(this.getScalar(idx1, idx2).getValue() != 0d) {
                    checkList2[idx1] = idx2;
                    break;
                }
            }
        }
        for(int idx =0; idx<checkList1.length-1; idx ++)
        {
            if(checkList2[idx] - checkList2[idx+1] >= 0)
                return false;
        }
        //조건 3. 선행계수 1이 존재하는 열은 선행 계수 1 이외의 원소가 전부 0이어야 함
        int pivotidx = 0;
        while(checkList2[pivotidx] != 0) {
            for(int idx =0; idx < this.getSizeRow(); idx ++) {
                if(idx != pivotidx && this.getScalar(idx, checkList2[pivotidx]).getValue() != 0)
                    return false;
            }
            pivotidx ++;
            if(pivotidx > this.getSizeRow()) break;
        }

        checkList1 = null; //이제 안씀
        checkList2 = null; //이제 안씀
        return true;
    }

    //행렬은 자신의 행렬식을 구해줄 수 있다. (nxn 행렬) (determinant)
    Scalar getDeterminant();

    //행렬은 자신의 역행렬을 구해줄 수 있다. (nxn 행렬) ## 예외 클래스 정의
    Matrix getInverseMatrix() throws NonSquareMatrixException, NonInvertibleMatrixException;

    //클론 함수 오버라이딩
    @Override
    public Object clone() throws CloneNotSupportedException {
        Matrix newMatrix = (Matrix) super.clone();
        Scalar[][] tmpMatrix = new Scalar[][];
        for (int idx = 0; idx < getSizeRow(); idx++) {
            tmpMatrix[idx] = (Scalar[]) MatrixValue.get(idx).toArray();
        }
        newMatrix.setMatrix(tmpMatrix);
        return newMatrix;
    }

    public ArrayList<ArrayList<Scalar>> getMatrixArray() {
        return (ArrayList<ArrayList<Scalar>>) MatrixValue.clone();
    }
}
