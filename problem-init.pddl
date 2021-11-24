(define (problem moveitemtoroom)
  (:domain turtlebot3-domain)
  (:objects
    turtlebot - robot
 initial-room - room
    pantry - room
    living-room - room
    study - room
    storage-room - room
    orange - item
  )

  (:init
    (at turtlebot initial-room)
    (in orange study)
    (hand_empty turtlebot)
  )

