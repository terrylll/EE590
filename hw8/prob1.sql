select Name AS TRACK_NAME, strftime('%M:%S',Milliseconds/1000/86400.0-0.5) AS DURATION  from Track INNER JOIN Album ON Album.AlbumId = Track.AlbumId where Album.Title = 'Temple of the Dog';