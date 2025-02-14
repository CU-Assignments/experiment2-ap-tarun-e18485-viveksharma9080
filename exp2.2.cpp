#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
stack<int> inputStack, outputStack;
void transfer() {
while (!inputStack.empty()) {
outputStack.push(inputStack.top());
inputStack.pop();
} }
public:
void push(int x) {
inputStack.push(x);
}
int pop() {
if (outputStack.empty()) {
transfer();
}
int top = outputStack.top();
outputStack.pop();
return top;
}
int peek() {
if (outputStack.empty()) {
transfer();
} return outputStack.top();
bool empty() {
return inputStack.empty() && outputStack.empty();
}
}
};
int main() {
MyQueue q;
q.push(1);
q.push(2);
cout << "Peek: " << q.peek() << endl; // Outputs 1
cout << "Pop: " << q.pop() << endl; // Outputs 1
cout << "Empty: " << q.empty() << endl; // Outputs 0 (false)
return 0;
}
