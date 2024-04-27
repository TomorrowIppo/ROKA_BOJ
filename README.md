# ROKA_BOJ
전역(23.05.30 ~ 24.11.29)하기 전까지 백준 문제 풀기 및 유형 정리<br/><br/><br/><br/>

# :rocket:알고리즘 시간복잡도 실압근
### STL
- 중복 제거(unique) : unique 자체는 $O(N)$이지만, erase(unique()) 형태면 $O(NM)$
<br/> 기본 형태 : ***v1.erase(unique(v1.begin(), v1.end()), v1.end());***

### Graph & Search
- DFS / BFS : $O(V + E)$
- 위상정렬 : $O(V + E)$
- Union-Find : 기본적으로 Find 함수에 의해 시간복잡도가 좌우되며, $O(logN)$, 최악의 경우 $O(N)$이다. 

### Data Structure
- 우선순위 큐 : 삽입, 삭제, front 가져오기 $O(logN)$
- 이분탐색 : $O(logN)$
- 투 포인터 : $O(N)$<br/><br/><br/><br/>

# :rocket:PS 모듈러 곱셈 역원 , 분할 정복을 이용한 거듭제곱 ( 보통 세트로 나옴 )

# :rocket:PS 정수론 실압근
- 에라토스테네스의 체 : $O(Nlog(logN))$
    -
    소수를 판별할 때 사용<br/>
    ```
    void primeNumberSieve()
    {
        // primeNum 배열 초기화
        for (int i = 2; i <= number; i++)
        {
            primeNum[i] = i;
        }

        for (int i = 2; i <= sqrt(number); i++)
        {
            // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
            if (primeNum[i] == 0)
                continue;
            // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
            for (int j = i * i; j <= number; j += i)
                primeNum[j] = 0;
        }

        // 소수 출력
        for (int i = 2; i <= number; i++)
        {
            if (primeNum[i] != 0)
                printf("%d\n", primeNum[i]);
        }
    }
    - by Dgos
    ```
- 오일러의 피 : $O(NlogN)$
    -
    소수에 대한 전처리(에라토스테네스의 체)가 돼있다면 
    $O(N^{\frac{1}{2}})$<br/><br/>
- 최대공약수(GCD) : $O(logN)$
    -
    유클리드 호제법(Euclidean Algorithm)을 이용. a를 b로 나눈 나머지를 r이라고 할 때 (단, a > b) a와 b의 최대 공약수는 b와 r의 최대 공약수와 같다 즉, $gcd(a, b) = gcd(b, r)$
    ```
    int GCD(int a, int b)
    { 
        if(b == 0) return a;
        else return GCD(b, a % b);
    }
    ```
    r = 0이라면, a, b의 최대공약수는 b가 된다.<br/><br/>

- 최소공배수(LCM) : $O(log(N + M))$
    -
    ```
    int LCM(int a, int b, int gcd) { return (a * b) / gcd; }
    ```
<br/><br/><br/><br/>
# :rocket:PS 조합론 실압근

- 순열
    -
1. ***순열*** : 순서를 따지고, 중복을 허용하지 않는다. (순서 O, 중복 X 
$_{n}^{}P_{r}^{} = \frac{n!}{(n - r)!}$
    ```
    int pArr[r] = { 0, };
    bool check[n + 1] = { false, }; 

    void permutation(int depth){
        if(depth == r){
            printArray(pArr);
            return;
        }
        
        for(int i = 1; i <= n; i++){
            if(!check[i]){
                check[i] = true;
                pArr[depth] = i;
                permutation(depth + 1);
                check[i] = false;
            }
        }
    }
    ```
    <br/>2. ***중복순열*** : 순서를 따지고, 중복을 허용한다. (순서 O, 중복 O
    $_{n}^{}\pi_{r}^{} = n^r$
    ```
    int dpArr[r] = { 0, };

    void duplicatePermutation(int depth){
        if(depth == r){
            printArray(dpArr);
            return;
        }

        for(int i = 1; i <= n; i++){
            dpArr[depth] = i;
            duplicatePermutation(depth + 1);
        }
    }
    ```
- 조합
    -
1. ***조합*** : 순서를 따지지도 않고, 중복을 허용하지 않는다. (순서 X, 중복 X $_{n}^{}C_{r}^{} = \frac{n!}{r!(n - r)!}$
    ```
    int cArr[r] = { 0, };

    void combination(int depth, int next){
        if(depth == r){
            printArray(cArr);
            return;
        }

        for(int i = next; i <= n; i++){
            cArr[depth] = i;
            combination(depth + 1, i + 1);
        }
    }
    ```
    <br/>2. ***중복조합*** : 순서를 따지지도 않고, 중복을 허용한다. (순서 X, 중복 O 
    $_{n}^{}H_{r}^{} = _{n + r - 1}^{}C_{r}^{}$
    ```
    int dcArr[r] = { 0, };

    void duplicateCombination(int depth, int next){
        if(depth == r){
            printArray(dcArr);
            return;
        }

        for(int i = next; i <= n; i++){
            dcArr[depth] = i;
            duplicateCombination(depth + 1, i);
        }
    }
    ```
<br/><br/><br/><br/>
# :rocket:PS 기하학 실압근