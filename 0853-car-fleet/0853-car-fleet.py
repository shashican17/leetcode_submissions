class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pack = sorted(zip(position, speed), reverse=True)
        n = len(position)

        stack = deque()
        
        for pos, spd in pack:
            time = (target - pos) / spd

            if not stack or stack[-1] < time:
                stack.append(time)
            

        return len(stack)