(define (problem moveitemtoroom)
  (:domain turtlebot3-domain)
  (:objects
    turtlebot - robot
 initial-room - room
    study - room
    storage-room - room
    090784 - room
    orange - item
  )

  (:init
    (at turtlebot initial-room)
    (in orange study)
    (hand_empty turtlebot)
  )

  (:goal
    (in orange storage-room)
  )
)
