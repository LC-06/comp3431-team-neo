(define (problem moveitemtoroom)
  (:domain turtlebot3-domain)
  (:objects
    turtlebot - robot
 initial-room - room
    pantry - room
    living-room - room
    kitchen - room
    study - room
    storage-room - room
    fanta apple orange - item
  )

  (:init
    (at turtlebot initial-room)
    (in apple kitchen)
    (in fanta kitchen)
    (in orange study)
    (hand_empty turtlebot)
  )

  (:goal
    (in orange storage-room)
  )
)
