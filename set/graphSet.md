# **집합**
: 명확히 구별이 가능한, 순서가 없는 원소들의 집단.

## 집합의 두가지 문제
 #### 1. 검색(Find)의 문제
    : 어떤 원소가 어떤 집합에 포함되는지 아닌지를 알아내는 문제
 #### 2. 결합(Union)의 문제
    : 두 개의 서로 다른 집합을 하나의 집합으로 합치는 문제

<br>

## **집합의 표현 방식**

## 1. 그래프 그 자체를 집합으로 보는 방식
 : 그래프에서 어느 하나의 연결 요소에 속하는 정점들은 모두 같은 집합으로 볼 수 있다.   
    => 어느 두 정점의 연결 유무를 파악할 수 있지만,    
        비효율적. 왜??   

        1.1 결합의 문제
            그래프로 표현된 집합의 경우 어떻게 연산을 일관되게 수행할 것인가의 문제.
        1.2 검색의 문제
            DFS나 BFS를 통해 주어진 두개의 정점 중 하나에서 시작해 다른 정점을 만날 때까지
            검색을 수행할 텐데, 이는 결국 해당 검색을 통해 생성되는 신장트리의 높이에 따라 효율이 결정된다.
            이 신장트리의 높이를 효율적으로 조절하는 방법이 어렵다.
            
        


**=> 집합을 표현하기에 매우 적절한 트리 구조를 정의해본다.**

## 2. 트리로 표현하는 집합

 #### **분리집합 (== 상향식 트리)**
    자식이 부모의 위치 하나만을 저장하는 방식.
    하나의 트리는 하나의 집합을 의미하며, 그 루트는 트리 전체를 대표한다.
    포인터로 구현할 수 있지만 배열로도 구현이 가능하다.


****