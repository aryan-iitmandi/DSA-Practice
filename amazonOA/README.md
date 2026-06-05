# Coding Assessment Questions – README

This document contains the **precisely reconstructed problem statements** for two technical coding questions along with clear specifications, constraints, and examples.

---

# Question 1 — Minimum Security Groups

## Problem Description

A financial services company is deploying a **private cloud network on AWS**. Due to the sensitive nature of the company's operations, AWS recommends implementing a **security grouping mechanism** for the servers.

There are **n servers** in the network. Each server has a required **security grade**, represented by the integer array:

```
security[i]
```

Where:

* `security[i]` represents the **security grade required by the i-th server**.

To maintain proper security standards, AWS recommends the following rules when forming **security groups**:

### Security Group Rules

1. **All servers in a group must have the same security grade.**

2. **The number of servers in any two groups must not differ by more than 1.**

   This means if one group has size `x`, another group can only have size:

```
x or x ± 1
```

### Objective

Determine the **minimum number of security groups required** such that both rules are satisfied.

---

## Function Signature

```
int findMinimumGroups(vector<int> security)
```

### Parameters

| Parameter | Type        | Description                   |
| --------- | ----------- | ----------------------------- |
| security  | vector<int> | Security grade of each server |

### Returns

```
int
```

Minimum number of groups required.

---

## Constraints

```
1 ≤ n ≤ 100000
1 ≤ security[i] ≤ 100000
```

---

## Input Format (Custom Testing)

```
n
security[0]
security[1]
...
security[n-1]
```

---

## Example

### Input

```
n = 6
security = [2, 3, 3, 3, 2, 1]
```

### Possible Grouping

```
Group 1 → [3, 3]
Group 2 → [3]
Group 3 → [2, 2]
Group 4 → [1]
```

### Output

```
4
```

---

## Sample Case

### Input

```
5
1
7
7
7
1
```

### Interpreted Array

```
security = [1,7,7,7,1]
```

### Output

```
2
```

### Explanation

```
Group 1 → [7,7,7]
Group 2 → [1,1]
```

Group sizes differ by **1**, which satisfies the rule.

---

# Question 2 — Maximize Secure Deliveries

## Problem Description

You are managing **delivery storage for a logistics company**. Deliveries arrive in logs, where each log contains a certain number of parts.

The parts must be stored across **k warehouses**.

You are given:

```
deliveryLogs[i]
```

Where:

* `deliveryLogs[i]` represents the **number of parts delivered in the i-th log**.

You are also given an **even integer `k`**, representing the total number of available warehouses.

---

## Storage Rules

1. **Each warehouse can store deliveries from only one delivery log.**

2. **A single delivery log may be split across multiple warehouses.**

3. After storing all deliveries:

   * The **k/2 warehouses with the largest number of deliveries will be compromised**.
   * The **remaining k/2 warehouses will remain secure**.

4. Only deliveries stored in the **secure warehouses are considered safe**.

---

## Objective

Determine the **maximum number of deliveries that can remain secure** after the compromised warehouses are removed.

---

## Function Signature

```
int maximizeSecureDelivery(vector<int> deliveryLogs, int k)
```

---

## Parameters

| Parameter    | Type        | Description                        |
| ------------ | ----------- | ---------------------------------- |
| deliveryLogs | vector<int> | Number of deliveries in each log   |
| k            | int         | Number of warehouses (always even) |

---

## Returns

```
int
```

Maximum number of deliveries that can remain **secure**.

---

## Constraints

```
1 ≤ n ≤ 1000
2 ≤ k ≤ 1000
k is even
0 ≤ deliveryLogs[i] ≤ 1000
```

---

## Input Format (Custom Testing)

```
n
deliveryLogs[0]
deliveryLogs[1]
...
deliveryLogs[n-1]
k
```

---

## Example

### Input

```
deliveryLogs = [3,5,9,6]
k = 4
```

### Possible Warehouse Distribution

```
Warehouse 1 → 5
Warehouse 2 → 4
Warehouse 3 → 5
Warehouse 4 → 6
```

### Compromised Warehouses

```
6, 5
```

### Secure Warehouses

```
5, 4
```

### Secure Deliveries

```
5 + 4 = 9
```

### Output

```
9
```

---

## Explanation

Since the **largest k/2 warehouses are compromised**, the strategy is to distribute deliveries such that the **remaining k/2 warehouses contain as many deliveries as possible**.

The objective is to maximize:

```
sum of the smallest k/2 warehouses
```

after distribution.

---

# End of Document
