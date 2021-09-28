def solution(enter, leave):
    answer = [0 for i in range(len(leave))]
    room = []
    idx = 0
    for i in range(len(leave)):
        if leave[i] in room:
            room.remove(leave[i])
            answer[leave[i]-1] += len(room)
            for j in range(len(room)):
                answer[room[j]-1] += 1
        else:
            while idx < len(enter) and enter[idx] != leave[i]:
                room.append(enter[idx])
                idx += 1
            answer[leave[i]-1] += len(room)
            for j in range(len(room)):
                answer[room[j]-1] += 1
            idx+=1
    return answer